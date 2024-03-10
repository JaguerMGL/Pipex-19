/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:15:26 by ndessard          #+#    #+#             */
/*   Updated: 2024/03/09 12:54:10 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	first_process(char **av, char **envp, t_data *data)
{
	if (close(data->fd[0]) == -1)
		error(0);
	data->infile = open(av[1], O_RDONLY | O_CLOEXEC, 0777);
	if (data->infile == -1)
	{
		close(data->fd[1]);
		error(0);
	}
	if (dup2(data->infile, STDIN_FILENO) == -1)
		error(0);
	if (close(data->infile) == -1)
		error(0);
	if (dup2(data->fd[1], STDOUT_FILENO) == -1)
		error(0);
	if (close(data->fd[1]) == -1)
		error(0);
	exec_com(av[2], envp, data);
}

static void	second_process(char **av, char **envp, t_data *data)
{
	data->outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (data->outfile == -1)
		error(0);
	if (dup2(data->prev_pip, STDIN_FILENO) == -1)
		error(0);
	if (dup2(data->outfile, STDOUT_FILENO) == -1)
		error(0);
	if (close(data->fd[1]) == -1)
		error(0);
	if (close(data->fd[0]) == -1)
		error(0);	
	if (close(data->outfile) == -1)
		error(0);
	exec_com(av[3], envp, data);
}

static void	ft_verif(int ac, char **envp, t_data *data)
{
	if (ac != 5)
		error(1);
	if (!envp || !*envp)
		error(3);
	data->fd[0] = -1;
	data->fd[1] = -1;
	data->prev_pip = -1;
	data->status = -1;
	data->infile = -1;
	data->outfile = -1;
	data->pid = -1;
	data->pid2 = -1;
	data->line = NULL;
	data->path = NULL;
	data->temp = NULL;
	data->cmd = NULL;
}

int	main(int ac, char **av, char **envp)
{
	t_data	data;

	ft_verif(ac, envp, &data);
	if (pipe(data.fd) == -1)
		error(0);
	data.pid = fork();
	if (data.pid == -1)
		error(0);
	if (data.pid == 0)
		first_process(av, envp, &data);
	data.prev_pip = data.fd[0];
	data.pid2 = fork();
	if (data.pid2 == 0)
		second_process(av, envp, &data);
	if (close(data.fd[0]) == -1)
		error(0);
	if (close(data.fd[1]) == -1)
		error(0);
	waitpid(data.pid, 0, 0);
	waitpid(data.pid2, 0, 0);
	return (0);
}
