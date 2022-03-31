#include "push_swap.h"
#include <stdio.h>

int main()
{
	char	*f = "28 -21 60 8 -68 36 91 -93 -72 -36";
	list	*a = reader(f);
	list	*b = 0;
	int	*m = parsing_int(f);
	int	len = 0;
	int	*lis;
	int	move = 0;

	ft_printlst(a);
	printf("............\n");
	ret_lis(&lis, m, nbr_of(f));
	len += push_lis(&a, &b, nbr_of(f), lis);
	ft_printlst(a);
	printf("....\n");
	ft_printlst(b);
	printf("............\n");
	rotate (&b);
	ft_printlst(b);
	printf("_________\n");
	move = many_rot_rev(a, b->content);
	printf("%d\n", move);
}
