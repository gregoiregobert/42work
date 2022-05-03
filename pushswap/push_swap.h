#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef	struct List
{
	int		content;
	struct	List	*next;
}			list;

list	*reader(char *inner);
list	*ft_lstnew_int(int content);
list	*ft_lstlast_int(list *lst);
list	*rotate_test(list *lst);
int	swap(list **lst);
int	push(list **a, list **b);
int	rotate(list **lst);
int	reverse(list **lst);
void	ft_lstclear_int(list **lst, void (*del)(int));
void	ft_lstadd_front_int(list **alst, list *new);
void	ft_lstadd_back_int(list **alst, list *new);
void	ft_printlst(list *lst);
void	ft_lis(int *seq, int **L, int **sub, int len);
void	ret_lis(int **lis, int *seq, int len);
int	ft_lstsize_int(list *lst);
int	arglen(char *str);
int	nbr_of(char *str);
int	*parsing_int(char *inner);
int	highest(int *L, int len);
int	*new_lis(int *seq, int *sub , int *L, int highest);
int	push_lis(list **a, list **b, int len_lis, int *lis);
int	smallest_lst(list *lst);
int	highest_lst(list *lst);
int	many_move_est(list *a, int b);
int	ft_rra(list *a, int b_cont);
int	ft_rrb(int size, int index);
int	between(list *a, int b_cont);
int	how_many(int rr_a, int rr_b);
int	best_move(list *a, list *b, int *move_a);
int	sort_rrr(list **a, list **b, int rrb, int move_a);
int	sort_rr(list **a, list **b, int rrb, int move_a);
int	sort_dif(list **a, list **b, int rrb, int move_a);
int	push_swap(list **a, list **b);
int	sort_best(list **a, list **b, int best_move, int *move_a);

#endif
