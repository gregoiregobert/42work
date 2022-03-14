#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	int	*data;
	struct	s_list;
}		list;

int	*reader(char *inner);
int	arglen(char *str);
int	nbr_of(char *str);
int	*init_stack_b(char *inner);
int	sb(int *stack_b, char *inner);
int	ss(int *stack_a, int *stack_b, char *inner);
int	is_empty(int *stack, char *inner);
int	first_element(int *stack_a, char *inner);
int	organized(int *stack, char *inner);


#endif
