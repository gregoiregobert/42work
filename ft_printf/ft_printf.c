/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:08:42 by ggobert           #+#    #+#             */
/*   Updated: 2021/12/23 14:12:38 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putchar_len(const char *command, int i, int len)
{
	ft_putchar(command[i]);
	return (len++);
}

int	print_function(const char *command, int i, va_list *arg)
{
	if (command[i] == 'c')
		return (print_c(arg));
	if (command[i] == 's')
		return (print_s(arg));
	if (command[i] == 'p')
		return (print_p(arg));
	if (command[i] == 'd' || command[i] == 'i')
		return (print_d_i(arg));
	if (command[i] == 'u')
		return (print_u(arg));
	if (command[i] == 'x')
		return (print_x(arg));
	if (command[i] == 'X')
		return (print_gx(arg));
	return (0);
}

int	print(const char *command, va_list *arg, int len, int pair)
{
	int	i;

	i = 0;
	while (command[i])
	{
		if (command[i] == '%' && command[i - 1] != '%')
			i++;
		if (command[i] != '%' && command[i - 1] != '%')
			putchar_len(command, i++, len++);
		if (command[i] != '%' && command[i - 1] == '%' && pair < 0)
		{
			putchar_len(command, i++, len++);
			pair *= -1;
		}
		if (command[i] != '%' && command[i - 1] == '%')
			len += print_function(command, i++, arg);
		if (command[i] == '%' && command[i - 1] == '%')
		{
			pair *= -1;
			if (pair < 0)
				putchar_len(command, i, len++);
			i++;
		}
	}
	return (len);
}

int	ft_printf(const char *command, ...)
{
	va_list	arg;
	int		len;
	int		pair;
	int		ret;

	pair = 1;
	len = 0;
	va_start(arg, command);
	ret = print(command, &arg, len, pair);
	va_end(arg);
	return (ret);
}
