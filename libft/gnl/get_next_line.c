/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:59:03 by ndessard          #+#    #+#             */
/*   Updated: 2024/02/12 14:56:26 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*str_rest(char *temp, int start)
{
	char	*rest;
	int		len;

	len = ft_strlen(temp) - start;
	if (len <= 0)
	{
		free(temp);
		return (NULL);
	}
	rest = ft_substr(temp, start, len);
	free(temp);
	return (rest);
}

static char	*cutting_line(char *temp, int *start_next)
{
	char	*line;
	int		i;

	i = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	if (temp[i] == '\n')
		*start_next = i + 1;
	else
	{
		*start_next = i;
		if (i == 0 && temp[i] == '\0')
			return (NULL);
	}
	line = ft_substr(temp, 0, *start_next);
	return (line);
}

static char	*n_line(int fd, char *buff, char *sav)
{
	char	*temp;
	int		b;

	while (!ft_strchr(sav, '\n'))
	{
		b = read(fd, buff, BUFFER_SIZE);
		if (b == 0 && sav[0] == '\0')
		{
			free(sav);
			return (NULL);
		}
		if (b <= 0)
			return (sav);
		buff[b] = '\0';
		temp = ft_strjoin(sav, buff);
		free(sav);
		sav = temp;
	}
	return (sav);
}

char	*get_next_line(int fd)
{
	static char	*saved;
	char		*buff;
	char		*line;
	int			i;

	if (saved == NULL)
		saved = ft_strdup("");
	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE >= INT_MAX)
	{
		free(saved);
		saved = NULL;
		return (NULL);
	}
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	saved = n_line(fd, buff, saved);
	free(buff);
	if (!saved)
		return (NULL);
	line = cutting_line(saved, &i);
	if (!line && !saved)
		return (NULL);
	saved = str_rest(saved, i);
	return (line);
}

// #include <stdio.h>
// #include <errno.h>
// #include <fcntl.h>

// char	*get_next_line(int fd);

// int main(int argc, char **argv)
// {
//     int fd;
//     if (argc != 2)
//     {
//         if (argc == 1)
//             write(1, "File name missing.\n", 19);
//         else if (argc > 2)
//             write(1, "Too many arguments.\n", 20);
//         return (1);
//     }
//     fd = open(argv[1], O_RDONLY);
//     if (fd < 0)
//     {
//         write(1, "Cannot read file.\n", 18);
//         return (1);
//     }

//     char *line;
//     // line = get_next_line(fd);
//     int i = 0;
//     while ((line = get_next_line(fd)) != NULL)
//     {
//         // printf("|%d line : %s",i, line);
//         // get_next_line(fd);
//         printf("%s", line);
//         free(line);
//         i++;
//     }
//     // system("leaks a.out");
//     close(fd);
//     return (0);
// }