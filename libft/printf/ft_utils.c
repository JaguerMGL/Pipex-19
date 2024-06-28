/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:44:40 by ndessard          #+#    #+#             */
/*   Updated: 2024/02/24 20:18:29 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_limit(long long nbr, int i)
{
	if (nbr == LONG_MIN)
	{
		write(1, "−9223372036854775808", 11);
		i = 11;
		return (i);
	}
	write (1, "0", 1);
	i = 1;
	return (i);
}

int	ft_hexa(void *ptr, int i, char c)
{
	long long	nbr;

	nbr = (long long)ptr;
	if (!ptr)
	{
		write (1, "0x0", 3);
		i = 3;
		return (i);
	}
	write (1, "0x", 2);
	i = 2;
	return (ft_prt_lhex(nbr, i, c));
}
