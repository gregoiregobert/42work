#include "push_swap.h"

int	*reader(char *inner)
{
	int	i;
	int	j;
	int	*stack_a;
	char	*nbr;

	i = nbr_of(inner);
	nbr = malloc(sizeof(char) * (arglen(inner) + 1));
	if (!nbr)
		return (0);
	stack_a = malloc(sizeof(int) * (nbr_of(inner) + 1));
	if (!stack_a)
		return (0);
	while (*inner)
	{
		j = 0;
		while (ft_isdigit(*inner) > 0)
			nbr[j++] = *inner++;
		nbr[j] = 0;
		if (j > 0)
			stack_a[--i] = ft_atoi(nbr);
		inner++;
	}
	return (stack_a);
}
