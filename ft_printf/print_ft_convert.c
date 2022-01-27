/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ft_convert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:32:11 by ggobert           #+#    #+#             */
/*   Updated: 2021/12/15 11:15:57 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_c(va_list *arg)
{
	char	c;

	if (!arg)
		return (0);
	c = va_arg (*arg, int);
	ft_putchar(c);
	return (1);
}

int	print_s(va_list *arg)
{
	char	*s;
	int		len;

	if (!arg)
		return (0);
	s = va_arg(*arg, char *);
	if (!s)
	{
		ft_putstr("(null)");
		return (6);
	}
	len = (int)ft_strlen(s);
	while (*s)
		ft_putchar(*s++);
	return (len);
}

int	print_p(va_list *arg)
{
	unsigned long long	p;

	p = va_arg(*arg, unsigned long long);
	ft_putstr("0x");
	ft_putnbr_base(p, "0123456789abcdef");
	return (ft_intbase_len(p, "0123456789abcdef") + 2);
}

int	print_d_i(va_list *arg)
{
	int	d_i;

	d_i = va_arg(*arg, int);
	ft_putnbr(d_i);
	return (ft_intlen(d_i));
}

int	print_u(va_list *arg)
{
	unsigned int	u;

	u = va_arg(*arg, unsigned int);
	ft_putnbr_u(u);
	return (ft_unsignedlen(u));
}
