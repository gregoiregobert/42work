#include "push_swap.h"

void	swap(list **lst)
{
	list	*temp;

	temp = (*lst)->next;
	(*lst)->next = temp->next;
	temp->next = *lst;
	*lst = temp;
}

void	push(list **a, list **b)
{
	list	*temp;

	temp = *a;
	*a =(*a)->next;
	temp->next = *b;
	*b = temp;
}

void	rotate(list **lst)
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
}

/*void	reverse(list **lst)
{
	ft
}*/
