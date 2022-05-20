/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_better_move_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:59:03 by ggobert           #+#    #+#             */
/*   Updated: 2022/05/20 15:59:05 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	better_last_sort(t_list1 *a)
{
	int	i;
	int	size;

	i = 0;
	size = ft_lstsize_int(a);
	while (a->content != smallest_lst(a))
	{
		a = a->next;
		i++;
	}
	if (i > (size / 2))
		i -= size;
	return (i);
}
