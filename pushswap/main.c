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
	t_len	len;

	f = "2 1 3 6 5 5 8";
	len.len_tot = nbr_of(f);
	len.i = 0;
	len.parsing = parsing_int(f, len.i);
	a = reader(f);
	b = 0;
	if (check_buffer(len.parsing, f, len.len_tot) > 0)
	{
		write(1, "error\n", 6);
		free (len.parsing);
		ft_lstclear_int(&a, NULL);
		return (0);
	}
	len.len_lis = ret_lis(&lis, len.parsing, len.len_tot);
	push_lis(&a, &b, &len, lis);
	push_swap(&a, &b);
	free (lis);
	free (len.parsing);
	ft_lstclear_int(&a, NULL);
}
