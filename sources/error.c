/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:55:18 by ndessard          #+#    #+#             */
/*   Updated: 2024/03/06 18:45:59 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	error(int i)
{
	if (i == 1)
		write(STDERR_FILENO, "INVALID_ARG\n", 12);
	else if (i == 2)
		write(STDERR_FILENO, "COMMAND_NOT_FOUND\n", 18);
	else if (i == 3)
		write(STDERR_FILENO, "Error\n", 6);
	else
		perror("pipex");
	exit(EXIT_FAILURE);
}
