/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:25:13 by marvin            #+#    #+#             */
/*   Updated: 2024/02/12 14:51:11 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	n;

	if (!s || !f)
		return (NULL);
	n = ft_strlen(s);
	str = ft_calloc(n + 1, sizeof(*str));
	if (!str)
		return (NULL);
	while (n--)
		str[n] = f(n, s[n]);
	return (str);
}
