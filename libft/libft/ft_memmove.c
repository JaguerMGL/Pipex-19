/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:44:00 by ndessard          #+#    #+#             */
/*   Updated: 2024/02/12 14:50:17 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*str_dst;
	unsigned char	*str_src;

	str_dst = (unsigned char *)dest;
	str_src = (unsigned char *)src;
	if (str_dst < str_src)
	{
		while (n--)
			*str_dst++ = *str_src++;
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
