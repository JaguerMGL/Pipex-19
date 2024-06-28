/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:55:18 by ndessard          #+#    #+#             */
/*   Updated: 2024/03/20 14:20:49 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	error(int i, t_data *data)
{
	if (i == 1)
	{
		write(STDERR_FILENO, "INVALID_ARG\n", 12);
		exit(EXIT_FAILURE);
	}
	else if (i == 2)
		write(STDERR_FILENO, "COMMAND_NOT_FOUND\n", 18);
	else if (i == 3)
		write(STDERR_FILENO, "INVALID_ENV\n", 12);
	else if (i == 4)
		write(STDERR_FILENO, "MALLOC_ERROR\n", 13);
	else
		perror("pipex");
	free_all(data);
	exit(EXIT_FAILURE);
}

static void	free_tab(char **tab, int n)
{
	int	i;

	i = 0;
	if (n == 0)
		while (tab[i])
			free(tab[i++]);
	free(tab);
}

void	free_all(t_data *data)
{
	int	i;

	i = 0;
	if (data->path_b || *data->path_b)
	{
		while (data->path_b[i])
			free(data->path_b[i++]);
		free(data->path_b);
	}
	i = 0;
	if (data->cmd)
	{
		while (i < data->nbr_cmd)
			free_tab(data->cmd[i++], 0);
		free(data->cmd);
	}
	if (data->path)
		free(data->path);
}
