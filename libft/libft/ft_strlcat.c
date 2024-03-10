/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:21:04 by ndessard          #+#    #+#             */
/*   Updated: 2024/02/12 14:50:58 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t dst_size)
{
	size_t	dst_len;
	size_t	src_len;

	if (!dst && src && dst_size == 0)
		return (0);
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_size <= dst_len)
		return (dst_size + src_len);
	ft_strlcpy(dst + dst_len, src, dst_size - dst_len);
	return (dst_len + src_len);
}
