/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:53:46 by ggobert           #+#    #+#             */
/*   Updated: 2022/05/04 14:13:29 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_lis(list **a, list **b, int max_len, int *lis)
{
	int		len;
	list	*temp;

	len = 0;
	while (max_len > 0)
	{
		if ((*a)->content == *lis)
		{
			lis++;
			len += rotate(a);
			max_len--;
		}
		if ((*a)->content != *lis)
		{
			len += push(a, b);
			max_len--;
		}
	}
	return (len);
}

int	best_move(list *a, list *b, int *move_a)
{
	int	i;
	int	move;
	int	index;
	int	size_b;

	i = 0;
	index = 0;
	size_b = ft_lstsize_int(b);
	move = how_many(ft_rra(a, b->content), ft_rrb(size_b, i));
	*move_a = ft_rra(a, b->content);
	while (++i < size_b && size_b >= 1)
	{
		b = b->next;
		if (how_many(ft_rra(a, b->content), ft_rrb(size_b, i)) < move)
		{
			move = how_many(ft_rra(a, b->content), ft_rrb(size_b, i));
			index = i;
			*move_a = ft_rra(a, b->content);
		}
	}
	return (index);
}

int	sort_best(list **a, list **b, int best_move, int *move_a)
{
	int	len;
	int	size_b;

	len = 0;
	size_b = ft_lstsize_int(*b);
	if (ft_rrb(size_b, best_move) < 0 && *move_a < 0)
		len += sort_rrr(a, b, ft_rrb(size_b, best_move), *move_a);
	else if (ft_rrb(size_b, best_move) > 0 && *move_a > 0)
		len += sort_rr(a, b, ft_rrb(size_b, best_move), *move_a);
	else
		len += sort_dif(a, b, ft_rrb(size_b, best_move), *move_a);
	len += push(b, a);
	return (len);
}

int	push_swap(list **a, list **b)
{
	int	len;
	int	best_m;
	int	move_a;

	len = 0;
	move_a = 0;
	while (*b)
	{
		best_m = best_move(*a, *b, &move_a);
		len += sort_best(a, b, best_m, &move_a);
	}
	return (len);
}
