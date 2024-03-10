/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:12:22 by ndessard          #+#    #+#             */
/*   Updated: 2024/02/26 14:58:37 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_freee(unsigned int count, ...)
{
	va_list	args;
	void	**tmp;

	va_start(args, count);
	while (count--)
	{
		tmp = va_arg(args, void **);
		if (*tmp)
		{
			free(*tmp);
			*tmp = NULL;
		}
	}
	va_end(args);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		str[j++] = s1[i];
	i = -1;
	while (s2[++i])
		str[j++] = s2[i];
	str[j] = '\0';
	ft_freee(2, &s1, &s2);
	return (str);
}

char	*ft_strjoin_frees2(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		str[j++] = s1[i];
	i = -1;
	while (s2[++i])
		str[j++] = s2[i];
	str[j] = '\0';
	free(s2);
	return (str);
}

char	*ft_read(int fd)
{
	char	*line;
	char	*file;
	char	*temp;

	if (fd <= 0)
	{
		write(2, "Error\nCannot read file.\n", 24);
		return (NULL);
	}
	file = ft_strdup("");
	line = get_next_line(fd);
	if (!line)
	{
		free(file);
		write(2, "Error\nEmpty map.\n", 17);
		return (NULL);
	}
	while (line)
	{
		temp = file;
		file = ft_strjoin_free(temp, line);
		line = get_next_line(fd);
	}
	close(fd);
	return (file);
}
