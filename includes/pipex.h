/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:12:41 by ndessard          #+#    #+#             */
/*   Updated: 2024/03/20 13:30:31 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/includes/libft.h"

typedef struct s_data
{
	int		fd[2];
	int		inv_in;
	int		in;
	int		out;
	int		prev_pipe;
	int		i;
	int		ac;
	int		status;
	int		nbr_cmd;
	int		nbr_pipe;
	char	*line;
	char	*path;
	char	**path_b;
	char	*temp;
	char	***cmd;
	char	**cmd_b;
	pid_t	pid;
	pid_t	pid2;
}	t_data;

void	error(int i, t_data *data);
void	exec_com(char *av, char **envp, t_data *data);
void	get_env(char **env, t_data *data);
void	get_cmd(char **av, t_data *data);
void	free_all(t_data *data);
void	child_process(char **env, char **av, t_data *data);
void	last_process(char **env, t_data *data, char **av);
char	*get_path(t_data *data, int j, char *cmd);
#endif