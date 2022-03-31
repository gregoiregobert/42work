#include "push_swap.h"

int	swap(list **lst)
{
	list	*temp;

	temp = (*lst)->next;
	(*lst)->next = temp->next;
	temp->next = *lst;
	*lst = temp;
	return (1);
}

int	push(list **from, list **to)
{
	list	*temp;

	temp = *from;
	*from =(*from)->next;
	temp->next = *to;
	*to = temp;
	return(1);
}

int	reverse(list **lst)
{
	list	*before_last;
	int	i;
	list	*temp;

	i = 1;
	before_last = *lst;
	while (i < (ft_lstsize_int(*lst) - 1))
	{
		before_last = before_last->next;
		i++;
	}
	temp = ft_lstlast_int(*lst);
	ft_lstlast_int(*lst)->next = *lst;
	*lst = temp;
	before_last->next = 0;
	return (1);
}

int	rotate(list **lst)
{
	list	*temp;

	temp = *lst;
	*lst = (*lst)->next;
	temp->next = 0;
	ft_lstlast_int(*lst)->next = temp;
	return (1);
}

list     *rotate_test(list *lst)
{
	list    *temp;

	temp = lst;
	lst = lst->next;
	temp->next = 0;
	ft_lstlast_int(lst)->next = temp;
	return (lst);
}
