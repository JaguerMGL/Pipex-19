/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 23:21:28 by ndessard          #+#    #+#             */
/*   Updated: 2024/03/09 12:44:15 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	utils(char **line, int i)
{
	i = -1;
	while (line[++i])
		free(line[i]);
	free(line);
}

static char	*find_path(char *cmd, char **envp, t_data *data)
{
	if (access(cmd, F_OK) == 0)
		return (cmd);
	while (ft_strnstr(envp[data->i], "PATH", 4) == 0)
		data->i++;
	data->line = ft_split(envp[data->i] + 5, ':');
	if (!data->line)
		return(NULL);
	data->i = -1;
	while (data->line[++data->i])
	{
		data->temp = ft_strjoin(data->line[data->i], "/");
		data->path = ft_strjoin(data->temp,cmd);
		if (data->temp)
			free(data->temp);
		if (access(data->path, F_OK) == 0)
			return (data->path);
		if (data->path)
			free(data->path);
	}
	utils(data->line, data->i);
	return (NULL);
}

void	exec_com(char *av, char **envp, t_data *data)
{
	data->i = 0;
	data->cmd = ft_split(av, ' ');
	if (!data->cmd || !*data->cmd)
		error(0);
	data->path = find_path(data->cmd[0], envp, data);
	data->i = -1;
	if (!data->path)
	{
		while (data->cmd[++data->i])
			free(data->cmd[data->i]);
		free(data->cmd);
		error(2);
	}
	if (execve(data->path, data->cmd, envp) == -1)
		error(0);
}
