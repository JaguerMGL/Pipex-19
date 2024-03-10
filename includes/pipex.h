/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:12:41 by ndessard          #+#    #+#             */
/*   Updated: 2024/03/09 11:45:30 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/includes/libft.h"

typedef struct	s_data
{
	int 	fd[2];
	int		infile;
	int		outfile;
	int		i;
	int		status;
	int		pip;
	int		prev_pip;
	int		ac;
	int		nbr_cmd;
	char	**line;
	char	*path;
	char	*temp;
	char	**cmd;
	pid_t	pid;
	pid_t	pid2;

}	t_data;


void	error(int i);
void    exec_com(char *av, char **envp, t_data *data);

#endif