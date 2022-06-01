/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 10:24:35 by ggobert           #+#    #+#             */
/*   Updated: 2022/05/31 16:56:23 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct List
{
	int			content;
	struct List	*next;
}			t_list1;

typedef struct len
{
	int		len_tot;
	int		len_lis;
	int		*parsing;
	int		i;
}			t_len;

t_list1	*parsing_chained(char *inner);
t_list1	*parsing_chained_av(char **av, int len);
t_list1	*ft_lstnew_int(int content);
t_list1	*ft_lstlast_int(t_list1 *lst);
t_list1	*rotate_test(t_list1 *lst);
t_list1	*arg_number(int ac, char **av, t_len *len);
int		swap(t_list1 **lst);
int		push(t_list1 **a, t_list1 **b);
int		rotate(t_list1 **lst);
int		reverse(t_list1 **lst);
int		reverse_a(t_list1 **lst);
int		reverse_b(t_list1 **lst);
void	ft_lstclear_int(t_list1 **lst, void (*del)(int));
void	ft_lstadd_front_int(t_list1 **alst, t_list1 *new);
void	ft_lstadd_back_int(t_list1 **alst, t_list1 *new);
void	ft_printlst(t_list1 *lst);
void	ft_lis(int *seq, int **L, int **sub, int len);
void	double_reverse(t_list1 **a, t_list1 **b, int ok);
void	double_rotate(t_list1 **a, t_list1 **b, int ok);
void	double_swap(t_list1 **a, t_list1 **b);
void	last_sort(t_list1 **a, int move);
void	small_sort(t_list1 **a, t_list1 **b, int len);
void	sort_3(t_list1 **a);
void	sort_5(t_list1 **a, t_list1 **b, int len);
void	case_1(t_list1 **a);
void	case_5(t_list1 **a);
void	rest_sort(t_list1 **a, t_list1 **b);
void	exec(t_list1 **a, t_list1 **b, char *command);
int		sort_command(t_list1 **a, t_list1 **b);
int		ret_lis(int **lis, int *seq, int len);
int		ft_lstsize_int(t_list1 *lst);
int		arglen(char *str);
int		nbr_of(char *str);
int		*parsing_int(char *inner, int i);
int		*parsing_int_av(char **av, int len);
int		highest(int *L, int len);
int		*new_lis(int *seq, int *sub, int *L, int highest);
int		push_lis(t_list1 **a, t_list1 **b, t_len *len, int *lis);
int		smallest_lst(t_list1 *lst);
int		highest_lst(t_list1 *lst);
int		many_move_est(t_list1 *a);
int		ft_rra(t_list1 *a, int b_cont);
int		ft_rrb(int size, int index);
int		between(t_list1 *a, int b_cont);
int		how_many(int rr_a, int rr_b);
int		best_move(t_list1 *a, t_list1 *b, int *move_a);
int		sort_rrr(t_list1 **a, t_list1 **b, int rrb, int move_a);
int		sort_rr(t_list1 **a, t_list1 **b, int rrb, int move_a);
int		sort_dif(t_list1 **a, t_list1 **b, int rrb, int move_a);
int		push_swap(t_list1 **a, t_list1 **b);
int		sort_best(t_list1 **a, t_list1 **b, int best_move, int *move_a);
int		check_digit(char *inner);
int		check_double_minus(char *inner);
int		check_doublon(int *stack_int, int len);
int		check_buffer(int *stack_int, int len, int ac, char **av);
int		ft_atoi_check(char *str);
int		check_int_max_min(char *inner);
int		better_last_sort(t_list1 *a);
int		check_already(t_list1 *a);

#endif
