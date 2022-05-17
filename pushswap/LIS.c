/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:32:33 by ggobert           #+#    #+#             */
/*   Updated: 2022/05/04 14:32:36 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//L'algorythme plus longue suite croissante 
void	ft_lis(int *seq, int **L, int **sub, int len)
{
	int	i;
	int	j;

	i = 1;
	while (i < len)
	{
		j = 0;
		while (j < i)
		{
			if (seq[j] < seq[i])
			{
				if ((*L)[i] < (*L)[j] + 1)
				{
					(*L)[i] = (*L)[j] + 1;
					(*sub)[i] = j;
				}
			}
			j++;
		}
		i++;
	}
}

//Renvoie le plus grand élément du TABLEAU d'INT L.
int	highest(int *L, int len)
{
	int	i;
	int	highest;

	i = 0;
	highest = 0;
	while (i < len)
	{
		if (L[i] > highest)
			highest = L[i];
		i++;
	}
	return (highest);
}

//Renvoie un TABLEAU d'INT LIS après exectution de l'algorytme LIS.
int	*new_lis(int *seq, int *sub, int *L, int highest)
{
	int	*lis;
	int	i;
	int	previous;

	i = 0;
	previous = 0;
	lis = malloc(sizeof(int) * highest);
	if (!lis)
		return (0);
	while (L[previous] != highest)
		previous++;
	i = highest;
	while (i > 0)
	{
		lis[--i] = seq[previous];
		previous = sub[previous];
	}
	return (lis);
}

//Fct général, initie les tableaux, et renvoie la LIS.
int	ret_lis(int **lis, int *seq, int len)
{
	int	i;
	int	*l;
	int	*sub;
	int	high;

	i = 0;
	l = malloc(sizeof(int) * len);
	if (!l)
		return (0);
	sub = malloc(sizeof(int) * len);
	if (!sub)
		return (0);
	while (i < len)
		l[i++] = 1;
	ft_lis(seq, &l, &sub, len);
	high = highest(l, len);
	*lis = new_lis(seq, sub, l, high);
	free (l);
	free (sub);
	return (high);
}
