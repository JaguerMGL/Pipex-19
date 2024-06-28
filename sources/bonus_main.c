/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:25:21 by ndessard          #+#    #+#             */
/*   Updated: 2024/03/20 14:21:07 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	init_value(int ac, t_data *data)
{
	data->i = -1;
	data->in = -1;
	data->inv_in = -1;
	data->out = -1;
	data->fd[0] = -1;
	data->fd[1] = -1;
	data->prev_pipe = -1;
	data->nbr_cmd = ac - 3;
	data->nbr_pipe = data->nbr_cmd - 1;
	data->line = NULL;
	data->cmd = NULL;
	data->cmd_b = NULL;
	data->temp = NULL;
	data->path = NULL;
	data->path_b = NULL;
}

static void	pipex(char **env, char **av, t_data *data)
{
	while (++data->i < data->nbr_pipe)
		child_process(av, env, data);
	if (data->i == data->nbr_pipe)
		last_process(env, data, av);
	while (wait(NULL) > 0)
		;
	close(data->fd[0]);
	close(data->fd[1]);
}

int	main(int ac, char **av, char **env)
{
	t_data	data;

	if (ac < 5)
		error(1, &data);
	data.ac = ac - 1;
	init_value(ac, &data);
	get_env(env, &data);
	get_cmd(av, &data);
	pipex(env, av, &data);
	free_all(&data);
	return (0);
}
