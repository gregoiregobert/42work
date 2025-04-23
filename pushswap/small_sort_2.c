/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:16:52 by ggobert           #+#    #+#             */
/*   Updated: 2022/05/24 13:22:12 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rest_sort(t_list1 **a, t_list1 **b)
{
	if ((*b)->content < smallest_lst(*a) || (*b)->content > highest_lst(*a))
	{
		push(b, a);
		write(1, "pa\n", 3);
		return ;
	}
	while (!((*b)->content < (*a)->content)
		|| !((*b)->content > ft_lstlast_int(*a)->content))
	{
		rotate(a);
		write(1, "ra\n", 3);
	}
	push(b, a);
	write(1, "pa\n", 3);
}
