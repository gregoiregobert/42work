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
			reverse(a);
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
