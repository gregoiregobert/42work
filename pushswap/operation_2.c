/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:56:01 by ggobert           #+#    #+#             */
/*   Updated: 2022/05/17 10:28:23 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse(t_list1 **lst)
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
	return (1);
}

void	double_reverse(t_list1 **a, t_list1 **b)
{
	reverse(a);
	reverse(b);
	write(1, "rrr\n", 4);
}

void	double_rotate(t_list1 **a, t_list1 **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
