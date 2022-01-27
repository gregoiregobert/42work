/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tool2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:25:27 by ggobert           #+#    #+#             */
/*   Updated: 2021/12/15 11:20:45 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

void	ft_putnbr_base(unsigned long long nbr, char *base)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if (nbr >= ft_strlen(base))
		ft_putnbr_base((nbr / ft_strlen(base)), base);
	ft_putchar(base[nbr % ft_strlen(base)]);
}

int	ft_intbase_len(unsigned long long nbr, char *base)
{
	int	len;

	len = 0;
	if (nbr == 0)
		len++;
	while (nbr)
	{
		nbr /= ft_strlen(base);
		len++;
	}
	return (len);
}

void	ft_putnbr_u(unsigned int nbr)
{
	if (nbr > 9)
		ft_putnbr_u(nbr / 10);
	ft_putchar(nbr % 10 + '0');
}

int	ft_unsignedlen(unsigned int nbr)
{
	unsigned int	len;

	len = 0;
	if (nbr == 0)
		len++;
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

void	ft_putnbr_base_u(unsigned int nbr, char *base)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if (nbr >= ft_strlen_u(base))
		ft_putnbr_base_u((nbr / ft_strlen_u(base)), base);
	ft_putchar(base[nbr % ft_strlen_u(base)]);
}
