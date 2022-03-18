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
list	**whos_rest(list **a, list **b);
int	swap(list **lst);
int	push(list **a, list **b);
int	rotate(list **lst);
int	reverse(list **lst);
void	ft_lstdelone_int(list *lst, void (*del)(int));
void	ft_lstadd_front_int(list **alst, list *new);
void	ft_lstadd_back_int(list **alst, list *new);
void	ft_printlst(list *lst);
int	half(list **a, list **b);
int	ft_sort(list **a, list **b);
int	ft_sort_rest(list **lst);
int	ft_merge(list **a, list **b);
int	ft_lstsize_int(list *lst);
int	arglen(char *str);
int	nbr_of(char *str);
int	check_all(list *lst);
int	check_next(list *lst);
int	rcheck_all(list *lst);
int	rcheck_next(list *lst);
int	higher(list *lst);

#endif
