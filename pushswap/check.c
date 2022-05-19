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

int	check_doublon(int *stack_int, int len)
{
	int	i;
	int	j;

	i = 1;
	while (i < len)
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

int	check_buffer(int *stack_int, int len, char **av)
{
	int	i;

	i = 0;
	if (check_doublon(stack_int, len) == 1)
		return (1);
	while (++i < len - 1)
	{
		if (check_digit(av[i]) == 1)
			return (1);
		if (check_double_minus(av[i]) == 1)
			return (1);
	}
	return (0);
}
