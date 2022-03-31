#include "push_swap.h"

int	many_move_est(list *a, int b)
{
	int	move;

	move = 0;
	while (a->content != smallest_lst(a))
	{
		a = a->next;
		move++;
	}
	if (move > (ft_lstsize_int(a) / 2))
		move -= ft_lstsize_int(a);
	return (move);
}

int	many_rot_rev(list *a, int b_cont)
{
	int	move;

	move = 0;
	if (b_cont < smallest_lst(a) || b_cont > highest_lst(a))
	{
		move += many_move_est(a, b_cont);
		return (move);
	}
	move += between(a, b_cont);
	return (move);
}

int	between(list *a, int b_cont)
{
	int	move;

	move = 0;
	while (!(a->content > b_cont) || !(ft_lstlast_int(a)->content < b_cont))
	{
		a = rotate_test(a);
		move++;
	}
	if (move > (ft_lstsize_int(a) / 2))
		move -= ft_lstsize_int(a);
	return (move);
}
