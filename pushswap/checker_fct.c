/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_fct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:55:29 by ggobert           #+#    #+#             */
/*   Updated: 2022/05/31 16:55:51 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec(t_list1 **a, t_list1 **b, char *command)
{
	if (ft_strncmp(command, "sa\n", 3) == 0)
		swap(a);
	if (ft_strncmp(command, "sb\n", 3) == 0)
		swap(b);
	if (ft_strncmp(command, "ss\n", 3) == 0)
		double_swap(a, b);
	if (ft_strncmp(command, "pa\n", 3) == 0)
		push(b, a);
	if (ft_strncmp(command, "pb\n", 3) == 0)
		push(a, b);
	if (ft_strncmp(command, "ra\n", 3) == 0)
		rotate(a);
	if (ft_strncmp(command, "rb\n", 3) == 0)
		rotate(b);
	if (ft_strncmp(command, "rr\n", 3) == 0)
		double_rotate(a, b, 0);
	if (ft_strncmp(command, "rra\n", 4) == 0)
		reverse(a);
	if (ft_strncmp(command, "rrb\n", 4) == 0)
		reverse(b);
	if (ft_strncmp(command, "rrr\n", 4) == 0)
		double_reverse(a, b, 0);
}

int	check_command(char *command)
{
	if (ft_strncmp(command, "sa\n", 3) == 0
		|| ft_strncmp(command, "sb\n", 3) == 0
		|| ft_strncmp(command, "ss\n", 3) == 0
		|| ft_strncmp(command, "pa\n", 3) == 0
		|| ft_strncmp(command, "pb\n", 3) == 0
		|| ft_strncmp(command, "ra\n", 3) == 0
		|| ft_strncmp(command, "rb\n", 3) == 0
		|| ft_strncmp(command, "rr\n", 3) == 0
		|| ft_strncmp(command, "rra\n", 4) == 0
		|| ft_strncmp(command, "rrb\n", 4) == 0
		|| ft_strncmp(command, "rrr\n", 4) == 0)
		return (1);
	return (0);
}

int	sort_command(t_list1 **a, t_list1 **b)
{
	char	*command;

	command = get_next_line(0);
	while (command)
	{
		if (check_command(command) == 0)
		{
			write(2, "Error\n", 6);
			free (command);
			return (0);
		}
		exec(a, b, command);
		free (command);
		command = get_next_line(0);
	}
	free (command);
	return (1);
}
