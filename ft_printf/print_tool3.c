/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tool3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:05:03 by ggobert           #+#    #+#             */
/*   Updated: 2021/12/15 11:21:35 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_intbase_len_u(unsigned int nbr, char *base)
{
	int	len;

	len = 0;
	if (nbr == 0)
		len++;
	while (nbr)
	{
		nbr /= ft_strlen_u(base);
		len++;
	}
	return (len);
}

unsigned int	ft_strlen_u(char *str)
{
	int	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}
