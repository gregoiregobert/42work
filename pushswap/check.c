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
		if (inner[i] == '-')
		{
			i++;
			if (ft_isdigit(inner[i]) != 1)
				return (1);
		}
		while (ft_isdigit(inner[i]) == 1)
			i++;
		if (inner[i] != ' ' && inner[i])
			return (1);
		while (inner[i] == ' ')
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
	if (!stack_int)
		return (0);
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

int	check_int_max_min(char *inner)
{
	int		j;
	char	*nbr;

	if (!inner)
		return (0);
	nbr = malloc(sizeof(char) * (arglen(inner) + 1));
	if (!nbr)
		return (0);
	while (*inner)
	{
		j = 0;
		while (*inner == '-' || ft_isdigit(*inner) > 0)
			nbr[j++] = *inner++;
		nbr[j] = 0;
		if (ft_atoi_check(nbr) == 1)
		{
			free (nbr);
			return (1);
		}
		inner++;
	}
	free (nbr);
	return (0);
}

int	check_buffer(int *stack_int, int len, int ac, char **av)
{
	int	i;

	i = 0;
	while (++i <= ac)
	{
		if (check_digit(av[i]) == 1)
			return (1);
		if (check_double_minus(av[i]) == 1)
			return (1);
		if (check_int_max_min(av[i]) == 1)
			return (1);
	}
	if (check_doublon(stack_int, len) == 1)
		return (1);
	if (check_int_max_min(av[1]) == 1)
		return (1);
	return (0);
}
