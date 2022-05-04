#include "push_swap.h"
#include <stdio.h>

int	ft_test(list **lst)
{
	int len;

	len = 0;

	len += reverse(lst);
	return (len);
}	

int main()
{
	char	*f = "74 -3";
	list	*a = reader(f);
	list	*b = 0;
	int	*m = parsing_int(f);
	int	bite = 0;
	int	*lis;

	ft_printlst(a);
	printf("\nLIS a :\n\n");
	ret_lis(&lis, m, nbr_of(f));
	bite += push_lis(&a, &b, nbr_of(f), lis);
	ft_printlst(a);
	printf("\nlist b :\n\n");
	ft_printlst(b);
	printf("..........\n");
	push_swap(&a, &b);
	ft_printlst(a);
	printf("len = %d\n", bite);
}
