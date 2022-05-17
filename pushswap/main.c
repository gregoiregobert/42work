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
	int		*lis;
	int		*parsing;

	f = "-29 -72 26 -78 214 11 -5 56 -9";
	parsing = parsing_int(f);
	a = reader(f);
	b = 0;
	if (check_buffer(parsing, f, nbr_of(f)) > 0)
	{
		write(1, "error\n", 6);
		return (0);
	}
	ret_lis(&lis, parsing, nbr_of(f));
	push_lis(&a, &b, nbr_of(f), lis);
	push_swap(&a, &b);
	free (parsing);
	free (lis);
	ft_lstclear_int(&a, NULL);
}
