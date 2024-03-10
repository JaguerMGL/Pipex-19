/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:47:11 by marvin            #+#    #+#             */
/*   Updated: 2024/02/12 15:46:07 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_verif(const char c, va_list args, int i)
{
	if (c == 'c')
		i += ft_prt_ch(va_arg(args, int));
	else if (c == 's')
		i += ft_prt_str(va_arg(args, char *));
	else if (c == 'p')
		i += ft_hexa(va_arg(args, void *), 0, 'x');
	else if (c == 'd')
		i += ft_prt_dec(va_arg(args, int), 0);
	else if (c == 'i')
		i += ft_prt_dec(va_arg(args, int), 0);
	else if (c == 'u')
		i += ft_prt_uns_dec(va_arg(args, unsigned int), 0);
	else if (c == 'x')
		i += ft_prt_ihex(va_arg(args, unsigned int), 0, c);
	else if (c == 'X')
		i += ft_prt_ihex(va_arg(args, unsigned int), 0, c);
	else if (c == '%')
		i += ft_prt_ch('%');
	else
		return (-1);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			i = ft_verif(*str, args, i++);
			if (i < 0)
				return (-1);
		}
		else
		{
			i += ft_putchar(*str);
			if (i < 0)
				return (-1);
		}
		str++;
	}
	va_end(args);
	return (i);
}
//  #include <stdio.h>
//  #include <stdint.h>
//  int main ()
//  {
// 	printf("Hola");
//  	return 0;
//  }