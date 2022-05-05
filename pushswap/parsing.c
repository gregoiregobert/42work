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

//Renvoie les nombres de la chaine de caractères en LISTE CHAINEE. 
t_list1	*reader(char *inner)
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
	return (stack_a);
}

//Renvoie les nombres de la chaine de caractères en TABLEAU d'INT. 
int	*parsing_int(char *inner)
{
	int		i;
	int		j;
	int		*stack_int;
	char	*nbr;

	stack_int = malloc(sizeof(int) * (nbr_of(inner)));
	if (!stack_int)
		return (0);
	i = 0;
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
			stack_int[i++] = ft_atoi(nbr);
		inner++;
	}
	return (stack_int);
}
