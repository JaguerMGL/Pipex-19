/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:45:29 by ndessard          #+#    #+#             */
/*   Updated: 2024/02/12 14:51:01 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size)
{
	size_t	i;

	i = ft_strlen(src);
	if (i + 1 < dst_size)
		ft_memcpy(dst, src, i + 1);
	else if (dst_size)
	{
		ft_memcpy(dst, src, dst_size - 1);
		dst[dst_size - 1] = '\0';
	}
	return (i);
}
