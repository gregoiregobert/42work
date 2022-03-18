#include "push_swap.h"

int	check_all(list *lst)
{
	while (lst->next)
	{
		if (lst->content > lst->next->content)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int	rcheck_all(list *lst)
{
	while (lst->next)
	{
		if (lst->content < lst->next->content)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int	check_next(list *lst)
{
	if (lst->content == higher(lst))
		return (0);
	if (lst->content > lst->next->content)
		return (1);
	return (0);
}

int	rcheck_next(list *lst)
{
	if (lst->next->content == higher(lst))
		return (0);
	if (lst->content < lst->next->content)
		return (1);
	return (0);
}

int	higher(list *lst)
{
	int	higher;

	higher = 0;
	while (lst)
	{
		if (lst->content > higher)
			higher = lst->content;
		lst = lst->next;
	}
	return (higher);
}
