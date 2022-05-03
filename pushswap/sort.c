#include "push_swap.h"

int	sort_rrr(list **a, list **b, int rrb, int move_a)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	printf("RRR\n");
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
	printf("RR\n");
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

int	sort_dif(list **a, list **b, int rrb, int mova)
{
	int	len;

	len = 0;
	printf("DIF\n");
	if (rrb < 0)
		while (rrb++ < 0)
			len += reverse(b);
	if (rrb > 0)
		while (rrb-- > 0)
			len += rotate(b);
	if (mova < 0)
		while (mova < 0)
		{
			len += reverse(a);
			mova++;
		}
	if (mova > 0)
		while (mova-- > 0)
			len += rotate (a);
	return (len);
}
