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

void	ft_printlst(list *lst)
{
	if (!lst)
	{
		printf("null\n");
		return ;
	}
	while (lst->next != 0)
	{
		printf("%d\n", lst->content);
		lst = lst->next;
	}
	printf("%d\n", lst->content);
}

void	ft_lstadd_back_int(list **alst, list *new)
{
	if (!*alst)
		*alst = new;
	else
		ft_lstlast_int(*alst)->next = new;
}

int	ft_lstsize_int(list *lst)
{
	int		i;
	list	*cursor;

	i = 0;
	cursor = lst;
	while (cursor)
	{
		cursor = cursor->next;
		i++;
	}
	return (i);
}

list	*ft_lstlast_int(list *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}

list	*ft_lstnew_int(int content)
{
	list	*new;

	new = malloc(sizeof(list));
	if (!new)
		return (0);
	if (!content)
		new->content = 0;
	new->content = content;
	new->next = NULL;
	return (new);
}
