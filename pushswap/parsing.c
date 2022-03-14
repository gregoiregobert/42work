#include "push_swap.h"

t_list	*reader(char *inner)
{
	int	i;
	int	j;
	list	*stack_a;
	char	*nbr;

	i = nbr_of(inner);
	nbr = malloc(sizeof(char) * (arglen(inner) + 1));
	if (!nbr)
		return (0);
	while (*inner)
	{
		j = 0;
		while (ft_isdigit(*inner) > 0)
			nbr[j++] = *inner++;
		nbr[j] = 0;
		if (j > 0)
			ft_lstadd_front(&stack_a, ft_lstnew(ft_atoi(nbr)));	
		inner++;
	}
	return (stack_a);
}
