/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:01:41 by ndessard          #+#    #+#             */
/*   Updated: 2024/03/20 14:11:41 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	open_file(char **av, t_data *data)
{
	data->in = open(av[1], O_RDONLY);
	if (data->in == -1)
	{
		write(2, "OPEN_ERROR\n", 11);
		data->inv_in = 1;
	}
}

static void	child_utils(t_data *data)
{
	if (data->inv_in == 1 && data->i == 0)
		error(0, data);
	if (data->i == 0)
	{
		dup2(data->in, STDIN_FILENO);
		close(data->in);
	}
	else
	{
		dup2(data->prev_pipe, STDIN_FILENO);
		close(data->prev_pipe);
	}
	close(data->fd[0]);
	data->path = get_path(data, 0, data->cmd[data->i][0]);
	if (data->path == NULL)
		write(2, "INVALID_CMD\n", 12);
	dup2(data->fd[1], STDOUT_FILENO);
	close(data->fd[1]);
}

void	child_process(char **av, char **env, t_data *data)
{
	if (pipe(data->fd) == -1)
		error(0, data);
	if (data->i == 0)
		open_file(av, data);
	data->pid = fork();
	if (data->pid == -1)
		error(0, data);
	if (data->pid == 0)
	{
		child_utils(data);
		if (execve(data->path, data->cmd[data->i], env) == -1)
			error(0, data);
	}
	else 
	{
		data->prev_pipe = data->fd[0];
		close(data->fd[1]);
	}
}

void	last_process(char **env, t_data *data, char **av)
{
	data->pid = fork();
	if (data->pid == -1)
		error(0, data);
	if (data->pid == 0)
	{
		data->out = open(av[data->ac], O_RDWR | O_CREAT | O_TRUNC, 0000644);
		dup2(data->prev_pipe, STDIN_FILENO);
		close(data->prev_pipe);
		data->path = get_path(data, 0, data->cmd[data->i][0]);
		if (data->path == NULL)
			write(2, "INVALID_LAST_CMD\n", 17);
		dup2(data->out, STDOUT_FILENO);
		close(data->fd[0]);
		close(data->fd[1]);
		close(data->out);
		if (execve(data->path, data->cmd[data->i], env) == -1)
			error(0, data);
	}
	close(data->fd[1]);
	return ;
}
