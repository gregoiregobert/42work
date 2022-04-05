#include "push_swap.h"

//L'algorythme de LIS.
void	ft_lis(int *seq, int **L, int **sub, int len)
{
	int	i;
	int	j;

	i = 1;
	while (i < len)
	{
		j = 0;
		while (j < i)
		{
			if (seq[j] < seq[i])
			{
				if ((*L)[i] < (*L)[j] + 1)
				{
					(*L)[i] = (*L)[j] + 1;
					(*sub)[i] = j;
				}
			}
			j++;
		}
		i++;
	}
}

//Renvoie le plus grand élément du TABLEAU d'INT L.
int	highest(int *L, int len)
{
	int	i;
	int	highest;

	i = 0;
	highest = 0;
	while (i < len)
	{
		if (L[i] > highest)
			highest = L[i];
		i++;
	}
	return (highest);
}
//Renvoie un TABLEAU d'INT LIS après exectution de l'algorytme LIS.
int	*new_lis(int *seq, int *sub , int *L, int highest)
{
	int	*lis;
	int	i;
	int	previous;

	i = 0;
	previous = 0;
	lis = malloc(sizeof(int) * highest);
	if (!lis)
		return 0;
	while (L[previous] != highest)
		previous++;
	i = highest;
	while (i > 0)
	{
		lis[--i] = seq[previous];
		previous = sub[previous];
	}
	return (lis);
} 

//FCT général qui initie les tableaux, et renvoie la LIS.
void	ret_lis(int **lis, int *seq, int len)
{
	int	i;
	int	*L;
	int	*sub;

	i = 0;
	L = malloc(sizeof(int) * len);
	if (!L)
		return ;
	sub = malloc(sizeof(int) * len);
	if (!sub)
		return ;
	while (i < len)
		L[i++] = 1;
	ft_lis(seq, &L, &sub, len);
	*lis = new_lis(seq, sub, L, highest(L, len));
}
