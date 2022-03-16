#include "push_swap.h"

void	ft_lstdelone_int(list *lst, void (*del)(int))
{
	del(lst->content);
	free(lst);
}

void	ft_lstadd_front_int(list **alst, list *new)
{
	if (alst && new)
	{
		new->next = *alst;
		*alst = new;
	}
}
