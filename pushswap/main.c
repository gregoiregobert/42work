/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:11:35 by ggobert           #+#    #+#             */
/*   Updated: 2022/05/05 11:11:37 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(void)
{
	char	*f = "123-23-99";
	t_list1	*a = reader(f);
	t_list1	*b = 0;
	int		*m = parsing_int(f);
	int		len = 0;
	int		*lis;

	if (check_inner(f) == 1)
			return (0);
	ft_printlst(a);
	printf("\nLIS a :\n\n");
	ret_lis(&lis, m, nbr_of(f));
	len += push_lis(&a, &b, nbr_of(f), lis);
	ft_printlst(a);
	printf("\nlist b :\n\n");
	ft_printlst(b);
	printf("..........\n");
	push_swap(&a, &b);
	while (a->content != smallest_lst(a))
		rotate(&a);
	ft_printlst(a);
	printf("len = %d\n", len);
}
