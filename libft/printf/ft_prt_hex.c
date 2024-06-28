/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prt_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:41:44 by ndessard          #+#    #+#             */
/*   Updated: 2024/02/12 15:00:06 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_prt_lhex(unsigned long nbr, int i, char c)
{
	const char	*lowcase;
	const char	*upcase;

	lowcase = "0123456789abcdef";
	upcase = "0123456789ABCDEF";
	if (nbr >= 16)
	{
		i = ft_prt_lhex(nbr / 16, i++, c);
		i = ft_prt_lhex(nbr % 16, i++, c);
	}
	else
	{
		if (c == 'x')
		{
			write (1, &lowcase[nbr], 1);
			i++;
		}
		if (c == 'X')
		{
			write (1, &upcase[nbr], 1);
			i++;
		}
	}
	return (i);
}

int	ft_prt_ihex(unsigned int nbr, int i, char c)
{
	const char	*lowcase;
	const char	*upcase;

	lowcase = "0123456789abcdef";
	upcase = "0123456789ABCDEF";
	if (nbr >= 16)
	{
		i = ft_prt_ihex(nbr / 16, i++, c);
		i = ft_prt_ihex(nbr % 16, i++, c);
	}
	else
	{
		if (c == 'x')
		{
			write (1, &lowcase[nbr], 1);
			i++;
		}
		if (c == 'X')
		{
			write (1, &upcase[nbr], 1);
			i++;
		}
	}
	return (i);
}
