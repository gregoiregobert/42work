/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 10:17:27 by ggobert           #+#    #+#             */
/*   Updated: 2022/05/05 10:17:33 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_printlst(t_list1 *lst)
{
	if (!lst)
	{
		printf("null\n");
		return ;
	}
	while (lst->next)
	{
		printf("%d\n", lst->content);
		lst = lst->next;
	}
	printf("%d\n", lst->content);
}

void	ft_lstadd_back_int(t_list1 **alst, t_list1 *new)
{
	if (!*alst)
		*alst = new;
	else
		ft_lstlast_int(*alst)->next = new;
}

int	ft_lstsize_int(t_list1 *lst)
{
	int		i;
	t_list1	*cursor;

	i = 0;
	cursor = lst;
	while (cursor)
	{
		cursor = cursor->next;
		i++;
	}
	return (i);
}

t_list1	*ft_lstlast_int(t_list1 *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_list1	*ft_lstnew_int(int content)
{
	t_list1	*new;

	new = malloc(sizeof(t_list1));
	if (!new)
		return (0);
	if (!content)
		new->content = 0;
	new->content = content;
	new->next = NULL;
	return (new);
}
