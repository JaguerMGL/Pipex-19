/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:33:12 by ndessard          #+#    #+#             */
/*   Updated: 2024/03/20 13:31:12 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	get_cmd(char **av, t_data *data)
{
	int	j;
	int	i;

	j = 0;
	i = 2;
	data->cmd = malloc(sizeof(char **) * (data->nbr_cmd + 1));
	if (!data->cmd)
		error(4, data);
	while (i < data->ac)
		data->cmd[j++] = ft_split(av[i++], ' ');
	data->cmd[j] = NULL;
}

void	get_env(char **env, t_data *data)
{
	int	i;

	i = -1;
	while (env[++i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			data->path_b = ft_split(&env[i][5], ':');
			if (!data->path_b)
				free_all(data);
		}
	}
	if (!data->path_b)
		write(2, "ENV_NOT_FOUND\n", 14);
}

char	*get_path(t_data *data, int j, char *cmd)
{
	if (access(cmd, X_OK) == 0)
		return (cmd);
	while (data->path_b[j])
	{
		data->temp = ft_strjoin(data->path_b[j], "/");
		data->line = ft_strjoin(data->temp, cmd);
		if (data->temp)
			free(data->temp);
		if (access(data->line, X_OK) == 0)
			return (data->line);
		if (data->line)
			free(data->line);
		j++;
	}
	return (NULL);
}
