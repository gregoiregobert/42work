/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 10:23:35 by ggobert           #+#    #+#             */
/*   Updated: 2022/05/05 10:23:40 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list1	*parsing_chained(char *inner)
{
	int		j;
	t_list1	*stack_a;
	char	*nbr;

	stack_a = 0;
	nbr = malloc(sizeof(char) * (arglen(inner) + 1));
	if (!nbr)
		return (0);
	while (*inner)
	{
		j = 0;
		while (*inner == '-' || ft_isdigit(*inner) > 0)
			nbr[j++] = *inner++;
		nbr[j] = 0;
		if (j > 0)
			ft_lstadd_back_int(&stack_a, ft_lstnew_int(ft_atoi(nbr)));
		inner++;
	}
	free (nbr);
	return (stack_a);
}

int	*parsing_int(char *inner, int i)
{
	int		j;
	int		*stack_int;
	char	*nbr;

	stack_int = malloc(sizeof(int) * (nbr_of(inner) + 1));
	if (!stack_int)
		return (0);
	nbr = malloc(sizeof(char) * (arglen(inner) + 1));
	if (!nbr)
		return (0);
	while (*inner)
	{
		j = 0;
		while (*inner == '-' || ft_isdigit(*inner) == 1)
			nbr[j++] = *inner++;
		nbr[j] = 0;
		if (j > 0)
			stack_int[i++] = ft_atoi(nbr);
		inner++;
	}
	free (nbr);
	return (stack_int);
}

int	*parsing_int_av(char **av, int len)
{
	int	i;
	int	*stack_int;

	i = -1;
	stack_int = malloc(sizeof(int) * (len + 1));
	if (!stack_int)
		return (0);
	while (++i < len)
	{
		if (ft_atoi_check(av[i + 1]) == 1)
		{
			free (stack_int);
			return (0);
		}
		stack_int[i] = ft_atoi(av[i + 1]);
	}
	return (stack_int);
}

t_list1	*parsing_chained_av(char **av, int len)
{
	int		i;
	t_list1	*stack_a;

	i = -1;
	stack_a = 0;
	while (++i < len)
		ft_lstadd_back_int(&stack_a, ft_lstnew_int(ft_atoi(av[i + 1])));
	return (stack_a);
}

t_list1	*arg_number(int ac, char **av, t_len *len)
{
	if (ac == 1)
	{
		len->parsing = 0;
		return (0);
	}
	if (ac == 2)
	{
		if (nbr_of(av[1]) > 1)
		{
			len->len_tot = nbr_of(av[1]);
			len->parsing = parsing_int(av[1], len->i);
			return (parsing_chained(av[1]));
		}
		len->len_tot = nbr_of(av[1]);
		len->parsing = 0;
		return (0);
	}
	else
	{
		len->len_tot = ac - 1;
		len->parsing = parsing_int_av(av, len->len_tot);
		return (parsing_chained_av(av, len->len_tot));
	}
}
