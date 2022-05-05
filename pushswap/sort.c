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

int	sort_rrr(list **a, list **b, int rrb, int move_a)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (rrb <= move_a)
	{
		while (i > move_a)
		{
			len += reverse(a);
			reverse(b);
			i--;
		}
		while (i-- > rrb)
			len += reverse(b);
	}
	if (rrb >= move_a)
	{
		while (i > rrb)
		{
			len += reverse(a);
			reverse(b);
			i--;
		}
		while (i-- > move_a)
			len += reverse(a);
	}	
	return (len);
}

int	sort_rr(list **a, list **b, int rrb, int move_a)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (rrb >= move_a)
	{
		while (i < move_a)
		{
			len += rotate(a);
			rotate(b);
			i++;
		}
		while (i++ < rrb)
			len += rotate(b);
	}
	if (rrb <= move_a)
	{
		while (i < rrb)
		{
			len += rotate(a);
			rotate(b);
			i++;
		}
		while (i++ < move_a)
			len += rotate(a);
	}
	return (len);
}

int	sort_dif(list **a, list **b, int rrb, int move_a)
{
	int	len;

	len = 0;
	if (rrb < 0)
		while (rrb++ < 0)
			len += reverse(b);
	else if(rrb > 0)
		while (rrb-- > 0)
			len += rotate(b);
	if (move_a < 0)
		while (move_a++ < 0)
			len += reverse(a);
	else if (move_a > 0)
		while (move_a-- > 0)
			len += rotate(a);
	return (len);
}
