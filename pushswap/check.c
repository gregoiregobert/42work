/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:05:37 by ggobert           #+#    #+#             */
/*   Updated: 2022/05/13 15:41:22 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_digit(char *inner)
{
	int	i;

	i = 0;
	while (inner[i])
	{
		if (inner[i] != '-' && ft_isdigit(inner[i]) == 0 && inner[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int	check_double_minus(char *inner)
{
	int	i;

	i = 0;
	while (inner[i])
	{
		if (inner[i] == '-')
		{
			i++;
			if (ft_isdigit(inner[i]) == 0)
				return (1);
		}
		i++;
	}
	return (0);
}

int	check_doublon(int *stack_int, int nbr_of)
{
	int	i;
	int	j;

	i = 1;
	while (i < nbr_of)
	{
		j = i;
		while (--j >= 0)
		{
			if (stack_int[i] == stack_int[j])
				return (1);
		}
		i++;
	}
	return (0);
}

int	check_buffer(int *stack_int, char *inner, int nbr_of)
{
	if (check_digit(inner) == 1
		|| check_double_minus(inner) == 1
		|| check_doublon(stack_int, nbr_of) == 1)
		return (1);
	return (0);
}
