#include "push_swap.h"

int	push_lis(list **a, list **b, int max_len, int *lis)
{
	int	len;
	list	*temp;

	len = 0;
	while (max_len > 0)
	{
		if ((*a)->content == *lis)
		{
			lis++;
			len += rotate(a);
			max_len--;
		}
		if ((*a)->content != *lis)
		{
			len += push(a ,b);
			max_len--;
		}
	}
	return len;
}

int	best_move(list *a, list *b, int *move_a)
{
	int	i;
	int	move;
	int	index;

	i = 0;
	index = 0;
	move = how_many(ft_rra(a, b->content), ft_rrb(b, i));
	while (b)
	{
		i++;
		if (how_many(ft_rra(a, b->content), ft_rrb(b, i)) < move)
		{
			move = how_many(ft_rra(a, b->content), ft_rrb(b, i));
			index = i;
			*move_a = ft_rra(a, b->content);
		}
		b = b->next;
	}
	return (index);
}

int	sort_best(list **a, list **b, int index)
{
	int	move_a;
	int	len;

	len = 0;
	if (ft_rrb(*b, index) < 0 && move_a < 0)
		len += sort_rrr(*a, *b, ft_rrb(*b, index), move_a);
	if (ft_rrb(*b, index) > 0 && move_a > 0)
		len += sort_rr(*a, *b, ft_rrb(*b, index), move_a);
	else
		sort_dif(*a, *b, ft_rrb(*b, index), move_a);
	len += push(*a, *b);
	return (len);
}

int	push_swap(list **a, list **b);
{
	int	len;
	int	move_a;

	len = 0;
	move_a = 0;
	while (*b)
		len += sort_best(*a, *b, best_move(**a, **b, &move_a);
	return (len);
}
