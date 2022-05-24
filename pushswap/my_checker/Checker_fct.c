/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Checker_fct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:55:29 by ggobert           #+#    #+#             */
/*   Updated: 2022/05/24 16:56:23 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../GNL/get_next_line.h"
#define BUFFER_SIZE 42

void exec(t_list1 **a, t_list1 **b, char *command)
{
    if (ft_strncmp(command, "sa\n", 3) == 0)
        swap(a);
    if (ft_strncmp(command, "sb\n", 3) == 0)
        swap(b);
    if (ft_strncmp(command, "ss\n", 3) == 0)
        swap_ab(a, b);
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

void    commamd_sort(t_list1 **a, t_list1 **b)
{
    char *command;

    command = get_next_line(0);
    exec(a, b, len, command);
    while (command)
    {
        command = get_next_line(0);
        exec(a, b, len, command);
    }
}
