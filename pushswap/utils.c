/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:10:15 by ggobert           #+#    #+#             */
/*   Updated: 2022/05/13 11:22:30 by ggobert          ###   ########.fr       */
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
		while (*str == '-' || ft_isdigit(*str) > 0)
		{
			temp++;
			str++;
		}
		if (temp > len)
			len = temp;
		str++;
	}
	return (len);
}

//Compte le nombre de nombres dans la CHAINE DE CARACTERES.
int	nbr_of(char *str)
{
	int	len;
	int	j;

	len = 0;
	while (*str)
	{
		j = 0;
		while (ft_isdigit(*str) == 0 && *str)
			str++;
		while (ft_isdigit(*str) == 1 && *str)
		{
			j = 1;
			str++;
		}
		if (j == 1)
			len++;
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

int	ft_atoi_check(char *str)
{
	int		pos;
	long	ret;

	pos = 1;
	ret = 0;
	if (ft_strlen(str) > 11)
		return (1);
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			pos *= -1;
	while (*str >= '0' && *str <= '9')
		ret = ret * 10 + (*str++ - '0');
	if ((ret * pos) > 2147483647 || (ret * pos) < -2147483648)
		return (1);
	return (0);
}
