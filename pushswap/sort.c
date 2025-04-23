/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 10:30:35 by ggobert           #+#    #+#             */
/*   Updated: 2022/05/05 10:30:37 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_rrr(t_list1 **a, t_list1 **b, int rrb, int move_a)
{
	int	i;

	i = 0;
	if (rrb <= move_a)
	{
		while (--i >= move_a)
			double_reverse(a, b, 1);
		while (i-- >= rrb)
		{
			reverse(b);
			write(1, "rrb\n", 4);
		}
	}
	if (rrb >= move_a)
	{
		while (--i >= rrb)
			double_reverse(a, b, 1);
		while (i-- >= move_a)
		{
			reverse(a);
			write(1, "rra\n", 4);
		}
	}	
	return (1);
}

int	sort_rr(t_list1 **a, t_list1 **b, int rrb, int move_a)
{
	int	i;

	i = 0;
	if (rrb >= move_a)
	{
		while (++i <= move_a)
			double_rotate(a, b, 1);
		while (i++ <= rrb)
		{
			rotate(b);
			write(1, "rb\n", 3);
		}
	}
	if (rrb <= move_a)
	{
		while (++i <= rrb)
			double_rotate(a, b, 1);
		while (i++ <= move_a)
		{
			rotate(a);
			write(1, "ra\n", 3);
		}
	}
	return (1);
}

int	sort_dif(t_list1 **a, t_list1 **b, int rrb, int move_a)
{
	if (rrb < 0)
		while (rrb++ < 0)
			reverse_b(b);
	else if (rrb > 0)
	{
		while (rrb-- > 0)
		{
			rotate(b);
			write(1, "rb\n", 3);
		}
	}
	if (move_a < 0)
		while (move_a++ < 0)
			reverse_a(a);
	else if (move_a > 0)
	{
		while (move_a-- > 0)
		{
			rotate(a);
			write(1, "ra\n", 3);
		}
	}
	return (1);
}

void	last_sort(t_list1 **a, int move)
{
	int	i;

	i = 0;
	if (move >= 0)
	{
		while (i++ < move)
		{
			rotate(a);
			write(1, "ra\n", 3);
		}
	}
	if (move < 0)
	{
		while (i-- > move)
			reverse_a(a);
	}
}
