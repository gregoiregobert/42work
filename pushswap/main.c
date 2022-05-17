/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:11:35 by ggobert           #+#    #+#             */
/*   Updated: 2022/05/13 11:13:40 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(void)
{
	char	*f;
	t_list1	*a;
	t_list1	*b;
	int		*m;
	int		*lis;
	int		len_lis;

	f = "-29 -72 26 -78 214 11 -5 56 -9";
	a = reader(f);
	b = 0;
	m = parsing_int(f);
	if (m == 0)
	{
		write(1, "error\n", 6);
		return (0);
	}
	if (check_buffer(m, f, nbr_of(f)) > 0)
	{
		write(1, "error\n", 6);
		return (0);
	}
	len_lis = ret_lis(&lis, m, nbr_of(f));
	push_lis(&a, &b, len_lis, lis);
	push_swap(&a, &b);
	ft_printlst(a);
}
