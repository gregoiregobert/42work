/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 13:55:26 by ggobert           #+#    #+#             */
/*   Updated: 2021/12/15 11:19:38 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	if (!str)
		return ;
	while (*str)
		ft_putchar(*str++);
}

void	ft_putnbr(int nbr)
{
	long int	l;

	l = nbr;
	if (l < 0)
	{
		ft_putchar('-');
		l *= -1;
	}
	if (l > 9)
		ft_putnbr(l / 10);
	ft_putchar(l % 10 + '0');
}

unsigned long long	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

int	ft_intlen(int nbr)
{
	long long	n;
	int			len;

	len = 0;
	n = nbr;
	if (nbr < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 9)
	{
		len++;
		n /= 10;
	}
	len++;
	return (len);
}
