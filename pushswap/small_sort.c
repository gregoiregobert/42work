/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:30:45 by ggobert           #+#    #+#             */
/*   Updated: 2022/05/23 15:13:20 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_list1 **a, t_list1 **b, int len)
{
	if (len == 3)
		sort_3(a);
	if (len > 3)
		sort_5(a, b, len);
}

void	sort_3(t_list1 **a)
{
	if ((*a)->content > (*a)->next->content)
	{
		if ((*a)->next->content > (*a)->next->next->content)
			case_1(a);
		else if ((*a)->next->content < (*a)->next->next->content)
		{
			if ((*a)->content < (*a)->next->next->content)
			{
				swap(a);
				write(1, "sa\n", 3);
			}
			else if ((*a)->content > (*a)->next->next->content)
			{
				rotate(a);
				write(1, "ra\n", 3);
			}
		}
	}
	else if ((*a)->content < (*a)->next->content)
	{
		if ((*a)->content < (*a)->next->next->content)
			case_5(a);
		else if ((*a)->content > (*a)->next->next->content)
			reverse_a(a);
	}
}

void	case_1(t_list1 **a)
{
	swap(a);
	write(1, "sa\n", 3);
	reverse_a(a);
}

void	case_5(t_list1 **a)
{
	swap(a);
	write(1, "sa\n", 3);
	rotate(a);
	write (1, "ra\n", 3);
}

void	sort_5(t_list1 **a, t_list1 **b, int len)
{
	push(a, b);
	write(1, "pb\n", 3);
	if (len == 5)
	{
		push(a, b);
		write(1, "pb\n", 3);
	}
	if (check_already(*a) == 0)
		sort_3(a);
	rest_sort(a, b);
	last_sort(a, better_last_sort(*a));
	if (len == 5)
		rest_sort(a, b);
	last_sort(a, better_last_sort(*a));
}
