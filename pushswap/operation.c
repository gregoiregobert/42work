/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 10:22:37 by ggobert           #+#    #+#             */
/*   Updated: 2022/05/05 10:22:40 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_list1 **lst)
{
	t_list1	*temp;

	if (!(*lst)->next)
		return (0);
	temp = (*lst)->next;
	(*lst)->next = temp->next;
	temp->next = *lst;
	*lst = temp;
	return (1);
}

int	push(t_list1 **from, t_list1 **to)
{
	t_list1	*temp;

	if (!*from)
		return (0);
	temp = *from;
	*from = (*from)->next;
	temp->next = *to;
	*to = temp;
	return (1);
}

int	reverse_a(t_list1 **lst)
{
	t_list1	*before_last;
	int		i;
	t_list1	*temp;

	i = 1;
	before_last = *lst;
	while (i++ < (ft_lstsize_int(*lst) - 1))
		before_last = before_last->next;
	temp = ft_lstlast_int(*lst);
	ft_lstlast_int(*lst)->next = *lst;
	*lst = temp;
	before_last->next = 0;
	write(1, "rra\n", 4);
	return (1);
}

int	reverse_b(t_list1 **lst)
{
	t_list1	*before_last;
	int		i;
	t_list1	*temp;

	i = 1;
	before_last = *lst;
	while (i++ < (ft_lstsize_int(*lst) - 1))
		before_last = before_last->next;
	temp = ft_lstlast_int(*lst);
	ft_lstlast_int(*lst)->next = *lst;
	*lst = temp;
	before_last->next = 0;
	write(1, "rrb\n", 4);
	return (1);
}

int	rotate(t_list1 **lst)
{
	t_list1	*temp;

	temp = *lst;
	*lst = (*lst)->next;
	temp->next = 0;
	ft_lstlast_int(*lst)->next = temp;
	return (1);
}
