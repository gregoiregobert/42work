#include "push_swap.h"
#include <stdio.h>

int main()
{
	char	*f = "90 999 9876 77 432    88893 9983\0";
	char	*g = "14 5671 5 771\0";
	list	*l = reader(f);
	list	*m = 0;

	ft_printlst(l);
	printf("....\n");
	ft_printlst(m);
	rotate(&l);
	rotate(&l);
        rotate(&l);
        rotate(&l);
	printf("____________\n");
	ft_printlst(l);
	printf("....\n");
	ft_printlst(m);
}
