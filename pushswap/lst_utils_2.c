#include "push_swap.h"

void	ft_lstclear_int(list **lst, void (*del)(int))
{
	list	*k;

	if (!*lst)
		return ;
	k = (*lst)->next;
	while (*lst)
	{
		k = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = k;
	}
}

void	ft_lstadd_front_int(list **alst, list *new)
{
	if (alst && new)
	{
		new->next = *alst;
		*alst = new;
	}
}
