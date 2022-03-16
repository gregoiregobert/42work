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
void	swap(list **lst);
void	push(list **a, list **b);
void	rotate(list **lst);
void	ft_lstdelone_int(list *lst, void (*del)(int));
void	ft_lstadd_front_int(list **alst, list *new);
void	ft_lstadd_back_int(list **alst, list *new);
void	ft_printlst(list *lst);
int	ft_lstsize_int(list *lst);
int	arglen(char *str);
int	nbr_of(char *str);

#endif
