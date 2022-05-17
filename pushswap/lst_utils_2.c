/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 10:22:12 by ggobert           #+#    #+#             */
/*   Updated: 2022/05/05 10:22:14 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear_int(t_list1 **lst, void (*del)(int))
{
	t_list1	*k;

	if (!*lst)
		return ;
	k = (*lst)->next;
	while (*lst)
	{
		k = (*lst)->next;
		if (del)
			del((*lst)->content);
		free(*lst);
		*lst = k;
	}
}

void	ft_lstadd_front_int(t_list1 **alst, t_list1 *new)
{
	if (alst && new)
	{
		new->next = *alst;
		*alst = new;
	}
}
