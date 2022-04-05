#include "push_swap.h"

//Trier 1er element de b, s'il est le plus grand ou le plus petit.
int	many_move_est(list *a, int b)
{
	int	move;

	move = 0;
	while (a->content != smallest_lst(a))
	{
		a = a->next;
		move++;
	}
	if (move > (ft_lstsize_int(a) / 2))
		move -= ft_lstsize_int(a);
	return (move);
}

//Trier 1er element de b, s'il n'est PAS le plus grand ou le plus petit. 
int	between(list *a, int b_cont)
{
	int	move;

	move = 0;
	while (!(a->content > b_cont) || !(ft_lstlast_int(a)->content < b_cont))
	{
		a = rotate_test(a);
		move++;
	}
	if (move > (ft_lstsize_int(a) / 2))
		move -= ft_lstsize_int(a);
	return (move);
}

//Renvoie nombres d'opérations nécessaires au tri du 1er element de B vers A.
int	ft_rra(list *a, int b_cont)
{
	int	move;

	move = 0;
	if (b_cont < smallest_lst(a) || b_cont > highest_lst(a))
	{
		move += many_move_est(a, b_cont);
		return (move);
	}
	move += between(a, b_cont);
	return (move);
}

//Renvoie le nombres d'opérations nécéssaires pour changer le 1er element de B.
int	ft_rrb(list *b, int index)
{
	int	rrb;

	if (index > (ft_lstsize_int(b) - 1) / 2)
		index -= ft_lstsize_int(b);
	return index;
}

//Renvoie le nombre d'operations pour trier un element de la LISTE CHAINEE B en fonction de son index.
int	how_many(int rr_a, int rr_b)
{
	if (rr_a < 0 && rr_b < 0)
	{
		if (rr_a > rr_b)
			return (rr_a);
		else
			return (rr_b);
	}
	if (rr_a > 0 && rr_b > 0)
	{
		if (rr_a < rr_b)
			return (rr_a);
		else
			return (rr_b);
	}
	else
	{
		if (rr_a < 0)
			rr_a *= -1;
		if (rr_b < 0)
			rr_b *= -1;
	}
	return (rr_a + rr_b);
