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
	char	*f = "-29 -72 26 -78 2147483647 11";
	t_list1	*a = reader(f);
	t_list1	*b = 0;
	int		*m;
	int		*lis;

	
	m = parsing_int(f);
	if (m == 0)
	{
		write(1, "error\n", 6);
		return (0);
	}
	if (check_buffer(m, f ,nbr_of(f)) > 0)
	{
		write(1, "error\n", 6);
		return (0);
	}
	ret_lis(&lis, m, nbr_of(f));
	push_lis(&a, &b, nbr_of(f), lis);
	push_swap(&a, &b);
	ft_printlst(a);
}
