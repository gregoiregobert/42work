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

//Compare la LIS(*int) et A, et push la non-LIS en B.
int	push_lis(t_list1 **a, t_list1 **b, t_len *len, int *lis)
{
	while (len->len_tot > 0)
	{
		if (len->len_lis > 0)
		{
			if ((*a)->content == *lis)
			{
				rotate(a);
				write(1, "ra\n", 3);
				lis++;
				len->len_lis--;
			}
			else
			{
				push(a, b);
				write(1, "pb\n", 3);
			}
		}
		else
		{
			push(a, b);
			write(1, "pb\n", 3);
		}
		len->len_tot--;
	}
	return (1);
}

//Renvoie index du trie de B vers A qui executera le moins d'operations.
int	best_move(t_list1 *a, t_list1 *b, int *move_a)
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

//execute le trie avec best_move, en optimisant avec les doubles (rrr, rr)
int	sort_best(t_list1 **a, t_list1 **b, int best_move, int *move_a)
{
	int	size_b;

	size_b = ft_lstsize_int(*b);
	if (ft_rrb(size_b, best_move) < 0 && *move_a < 0)
		sort_rrr(a, b, ft_rrb(size_b, best_move), *move_a);
	else if (ft_rrb(size_b, best_move) > 0 && *move_a > 0)
		sort_rr(a, b, ft_rrb(size_b, best_move), *move_a);
	else
		sort_dif(a, b, ft_rrb(size_b, best_move), *move_a);
	push(b, a);
	write(1, "pa\n", 3);
	return (1);
}

//programme final
int	push_swap(t_list1 **a, t_list1 **b)
{
	int	best_m;
	int	move_a;

	move_a = 0;
	while (*b)
	{
		best_m = best_move(*a, *b, &move_a);
		sort_best(a, b, best_m, &move_a);
	}
	last_sort(a, better_last_sort(*a));
	return (1);
}
