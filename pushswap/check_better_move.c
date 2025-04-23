/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_better_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:22:03 by ggobert           #+#    #+#             */
/*   Updated: 2022/05/04 14:22:07 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	many_move_est(t_list1 *a)
{
	int	move;
	int	size;

	move = 0;
	size = ft_lstsize_int(a);
	while (a->content != smallest_lst(a))
	{
		a = a->next;
		move++;
	}
	if (move > (size / 2))
		move -= size;
	return (move);
}

int	between(t_list1 *a, int b_cont)
{
	int	move;
	int	size;
	int	i;
	int	dif;
	int	bestdif;

	i = -1;
	size = ft_lstsize_int(a);
	bestdif = 0;
	while (++i < size)
	{
		dif = a->content - b_cont;
		if (dif > 0)
		{
			if (!bestdif || bestdif > dif)
			{
				bestdif = dif;
				move = i;
			}
		}	
		a = a->next;
	}
	if (move > (size / 2))
		move -= size;
	return (move);
}

int	ft_rra(t_list1 *a, int b_cont)
{
	int	move;

	move = 0;
	if (b_cont < smallest_lst(a) || b_cont > highest_lst(a))
	{
		move += many_move_est(a);
		return (move);
	}
	move += between(a, b_cont);
	return (move);
}

int	ft_rrb(int size, int index)
{
	if (size <= 2)
		return (index);
	if (index > (size / 2))
		index -= size;
	return (index);
}

int	how_many(int rr_a, int rr_b)
{
	if (rr_a < 0 && rr_b < 0)
	{
		if (rr_a < rr_b)
			return (rr_a * -1);
		else
			return (rr_b * -1);
	}
	if (rr_a > 0 && rr_b > 0)
	{
		if (rr_a > rr_b)
			return (rr_a);
		else
			return (rr_b);
	}
	else
	{
		if (rr_a < 0)
			rr_a *= -1;
		if (rr_b < 0)
			rr_b *= -1;
	}
	return (rr_a + rr_b);
}
