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

#include "../push_swap.h"
#include "../../GNL/get_next_line.h"

int	main(int ac, char **av)
{
	t_list1	*a;
	t_list1	*b;
	int		*lis;
	t_len	len;

	len.i = 0;
	a = arg_number(ac, av, &len);
	b = 0;
	if (check_buffer(len.parsing, len.len_tot, (ac - 1), av) == 1)
		write(2, "Error\n", 6);
	else if (a == 0 || len.len_tot == 1)
		return (0);
	sort_command(&a, &b);
	if (check_already(a, len.len_tot) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free (len.parsing);
	ft_lstclear_int(&a, NULL);
}
