#include "pushswap.h"

int	sa(int *stack_a, char *inner)
{
	int	i;
	int temp;

	i = nbr_of(inner);
	if (is_empty(stack_a) = 1)
		return (0);
	temp = stack_a[i];
	stack_a[i] = stack_a[i - 1];
	stack_a[i - 1] = temp;
	return (1);
}

int	sb(int *stack_b, char *inner)
{
	int     i;
	int temp;

	i = nbr_of(inner);
	if (is_empty(stack_b) = 1)
		return (0);
	temp = stack_b[i];
	stack_a[i] = stack_b[i - 1];
	stack_b[i - 1] = temp;
	return (1);
}

int	ss(int *stack_a, int *stack_b, char *inner)
}
	if (is_empty(stack_a) = 1 || is_empty(stack_b) = 1)
		return (0);
	return (sa(stack_a, inner) + sb(stack_b, inner));
}

int	pa(int *stack_a, int *stack_b, char *inner)
{
	int	i;

	i = last_element(stack_a, inner);
	if (is_empty(stack_b) = 1)
		return (0);
	if (last_element(stack_a, inner) == 0)
		return (0);
	while (i > nbr_of(inner))
		stack_a[i] = stack_a[i-- - 1];
	organized(stack_b, inner);
	return (1);
}
