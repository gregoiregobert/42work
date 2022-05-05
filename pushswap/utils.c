/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:10:15 by ggobert           #+#    #+#             */
/*   Updated: 2022/05/05 11:10:17 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Compte le nombre de caractère du nombre le plus grand dans la str.
int	arglen(char *str)
{
	int	len;
	int	temp;

	len = 0;
	while (*str)
	{
		temp = 0;
		while (ft_isdigit(*str++) > 0)
			temp++;
		if (temp > len)
			len = temp;
	}
	return (len);
}

//Compte le nombre de nombres dans la CHAINE DE CARACTERES.
int	nbr_of(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		if (ft_isdigit(*str) < 1)
			str++;
		if (ft_isdigit(*str) > 0)
			len++;
		while (ft_isdigit(*str) > 0)
			str++;
	}
	return (len);
}

//Renvoie le nombre le plus grand de la LISTE CHAINEE.
int	highest_lst(t_list1 *lst)
{
	int	highest;

	highest = lst->content;
	if (lst->next)
		lst = lst->next;
	while (lst)
	{
		if (lst->content > highest)
			highest = lst->content;
		lst = lst->next;
	}
	return (highest);
}

//Renvoie le nombre le plus petit de la LISTE CHAINEE.
int	smallest_lst(t_list1 *lst)
{
	int	smallest;

	smallest = lst->content;
	if (lst->next)
		lst = lst->next;
	while (lst)
	{
		if (lst->content < smallest)
			smallest = lst->content;
		lst = lst->next;
	}
	return (smallest);
}
