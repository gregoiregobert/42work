#include "push_swap.h"

int	arglen(char *str)
{
	int	len;
	int	temp;

	len = 0;
	while (*str)
	{
		temp = 0;
		while (ft_isdigit(*str++) > 0)
			temp++;
		if (temp > len)
			len = temp;
	}
	return (len);
}

int	nbr_of(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		if (ft_isdigit(*str) < 1)
			str++;
		if (ft_isdigit(*str) > 0)
			len++;	
		while (ft_isdigit(*str) > 0)
			str++;
	}
	return (len);
}

int	highest_lst(list *lst)
{
	int	highest;

	highest = lst->content;
	if (lst->next)
		lst = lst->next;
	while (lst)
	{
		if (lst->content > highest)
			highest = lst->content;
		lst = lst->next;
	}
	return (highest);
}

int	smallest_lst(list *lst)
{
	int	smallest;

	smallest = lst->content;
	if (lst->next)
		lst = lst->next;
	while (lst)
	{
		if (lst->content < smallest)
			smallest = lst->content;
		lst = lst->next;
	}
	return (smallest);
}
