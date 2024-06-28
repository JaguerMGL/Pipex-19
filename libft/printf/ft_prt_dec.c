/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prt_dec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:41:08 by ndessard          #+#    #+#             */
/*   Updated: 2024/02/12 15:00:02 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_prt_dec(long long nbr, int i)
{
	char	c;

	if (nbr == 0 || nbr == LONG_MIN)
		return (ft_limit(nbr, i));
	if (nbr < 0)
	{
		nbr = -nbr;
		write (1, "-", 1);
		i++;
	}
	if (nbr > 9)
		i = ft_prt_dec(nbr / 10, i++);
	c = (char)(nbr % 10) + '0';
	write (1, &c, 1);
	i++;
	return (i);
}
