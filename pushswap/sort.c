#include "push_swap.h"

int	sort_rrr(list **a, list **b, int rrb, int move_a)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	printf("++++++ RRR\nrb = %d\nmova = %d\n", rrb, move_a);
	if (rrb <= move_a)
	{
		while (i-- > move_a)
		{
			len += reverse(a);
			reverse(b);
		}
		while (i-- > rrb)
			len += reverse(b);
	}
	if (rrb >= move_a)
	{
		while (i-- > rrb)
		{
			len += reverse(a);
			reverse(b);
		}
		while (i-- > move_a)
			len += reverse(a);
	}	
	return (len);
}

int	sort_rr(list **a, list **b, int rrb, int move_a)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	printf("++++++ RR\nrb = %d\nmova = %d\n", rrb, move_a);
	if (rrb >= move_a)
	{
		while (i++ < move_a)
		{
			len += rotate(a);
			rotate(b);
		}
		while (i++ < rrb)
			len += rotate(b);
	}
	if (rrb <= move_a)
	{
		while (i++ < rrb)
		{
			len += rotate(a);
			rotate(b);
		}
		while (i++ < move_a)
			len += rotate(a);
	}
	return (len);
}

int	sort_dif(list **a, list **b, int rrb, int move_a)
{
	int	len;

	len = 0;
	printf("++++++ DIF\nrrb = %d\nmova = %d\n", rrb, move_a);
	if (rrb < 0)
		while (rrb++ < 0)
			len += reverse(b);
	if (rrb > 0)
		while (rrb-- > 0)
			len += rotate(b);
	if (move_a < 0)
		while (move_a++ < 0)
			len += reverse(a);
	if (move_a > 0)
		while (move_a-- > 0)
			len += rotate (a);
	return (len);
}
