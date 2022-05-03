#include "push_swap.h"
#include <stdio.h>

int main()
{
	char	*f = "99 81 -1 -29 -14 47 -60 90 78 26";
	list	*a = reader(f);
	list	*b = 0;
	int	*m = parsing_int(f);
	int	len = 0;
	int	*lis;

	ft_printlst(a);
	printf("\nLIS a :\n\n");
	ret_lis(&lis, m, nbr_of(f));
	len += push_lis(&a, &b, nbr_of(f), lis);
	ft_printlst(a);
	printf("\nlist b :\n\n");
	ft_printlst(b);
	printf("....\n");
	push_swap(&a, &b);
	ft_printlst(a);
}
