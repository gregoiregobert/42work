#include "push_swap.h"

int	half(list **a, list **b)
{
	int	h;
	int	i;
	int	len;

	len = 0;
	i = 0;
	h = ft_lstsize_int(*a) / 2;
	while (i < h)
	{
		len += push(a, b);
		printf("pb\n");
		i++;
	}
	return (len);
}

int	ft_sort(list **a, list **b)
{
	int	len;

	len = 0;
	while ((check_all(*a) == 1) && (check_all(*b) == 1))
	{
		if ((check_next(*a) == 1) && (check_next(*b) == 1))
		{
			len += swap (a);
			swap (b);
			printf("ss\n");
		}
		if (check_next(*a) == 1)
		{
			len += swap(a);
			printf("sa\n");
		}
		if (check_next(*b) == 1)
                {
                        len += swap(b);
                        printf("sb\n");
                }
		len += reverse(a);
		reverse(b);
		printf("rrr\n");
	}
	ft_sort_rest(whos_rest(a ,b));
	return (len);
}

int	ft_sort_rest(list **lst)
{
	int	len;

	len = 0;
	while (check_all(*lst) == 1)
	{
		if(check_next(*lst) == 1)
		{
			len += swap(lst);
			printf("sb\n");
		}
		len += reverse(lst);
		printf("rrb\n");
	}
	return (len);
}

list	**whos_rest(list **a, list **b)
{
	if (check_all(*a) == 1)
		return (a);
	return (b);
}

int	ft_merge(list **a, list **b)
{
	int	len;

	len = 0;
	while (*b && (*b)->content < higher(*a))
	{
		if ((*a)->content > (*b)->content)
		{
			len += push(b ,a);
			printf("pa\n");
		}
		len += reverse(a);
		printf("rra\n");
	}
	while ((*a)->content != higher(*a))
	{
		len += reverse(a);
		printf("rra\n");
	}
	len += reverse(a);
	printf("rra\n");
	while (*b)
	{
		len += push(b, a);
		printf("pa\n");
		len += reverse(a);
		printf("rra\n");
	}
	return (len);
}
