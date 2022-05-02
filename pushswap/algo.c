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
	while (i < ft_lstsize_int(b))
	{
		
		i++;
		b = b->next;
		if (how_many(ft_rra(a, b->content), ft_rrb(b, i)) < move)
		{
			move = how_many(ft_rra(a, b->content), ft_rrb(b, i));
			index = i;
			*move_a = ft_rra(a, b->content);
		}
	}
	return (index);
}

int	sort_best(list **a, list **b, int best_move)
{
	int	move_a;
	int	len;

	len = 0;
	if (ft_rrb(*b, best_move) <= 0 && move_a <= 0)
		len += sort_rrr(a, b, ft_rrb(*b, best_move), move_a);
	if (ft_rrb(*b, best_move) >= 0 && move_a >= 0)
		len += sort_rr(a, b, ft_rrb(*b, best_move), move_a);
	else
		sort_dif(a, b, ft_rrb(*b, best_move), move_a);
	len += push(b, a);
	return (len);
}

int	push_swap(list **a, list **b)
{
	int	len;
	int	best_m;
	int	move_a;

	len = 0;
	move_a = 0;
	while (*b)
	{
		best_m = best_move(*a, *b, &move_a);
		printf("best : %d\n", best_m);
		len += sort_best(a, b, best_m);
		ft_printlst(*a);
		printf("----------\n");
		ft_printlst(*b);
	}
	return (len);
}
