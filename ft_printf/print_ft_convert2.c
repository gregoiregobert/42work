/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ft_convert2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:26:52 by ggobert           #+#    #+#             */
/*   Updated: 2021/12/15 11:23:53 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_x(va_list *arg)
{
	long long	x;

	x = va_arg(*arg, long long);
	ft_putnbr_base_u(x, "0123456789abcdef");
	return (ft_intbase_len_u(x, "0123456789abcdef"));
}

int	print_gx(va_list *arg)
{
	long long	gx;

	gx = va_arg(*arg, long long);
	ft_putnbr_base_u(gx, "0123456789ABCDEF");
	return (ft_intbase_len_u(gx, "0123456789ABCDEF"));
}
