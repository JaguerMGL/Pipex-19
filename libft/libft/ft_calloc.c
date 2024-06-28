/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:49:09 by ndessard          #+#    #+#             */
/*   Updated: 2024/02/12 14:49:11 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	verif;

	verif = count * size;
	if (count != 0 && size != 0)
	{
		if (verif / count != size)
			return (NULL);
	}
	if (count == 0 || size == 0)
		verif = 0;
	ptr = malloc(verif);
	if (ptr)
	{
		ft_bzero(ptr, count * size);
		return (ptr);
	}
	else 
		return (NULL);
}
