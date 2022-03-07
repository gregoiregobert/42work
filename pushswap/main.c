#include "push_swap.h"

int main()
{
	int 	len = 8; 
	int	i = 0;
	int	*l;
	char	*f = "90 999 9876 77 432    88893 9983";

	while(i < nbr_of(f))
		printf("%d\n", reader(f)[i++]);
	return 0;
}
