#include "push_swap.h"

int	arglen(char *str)
{
	int	len;
	int	temp;

	len = 0;
	while (*str)
	{
		temp = 0;
		while (ft_isdigit(*str++) > 0)
			temp++;
		if (temp > len)
			len = temp;
	}
	return (len);
}

int	nbr_of(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		if (ft_isdigit(*str) < 1)
			str++;
		if (ft_isdigit(*str) > 0)
			len++;	
		while (ft_isdigit(*str) > 0)
			str++;
	}
	return (len);
}
