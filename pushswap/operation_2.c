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
	write(1, "rr\n", 4);
}
