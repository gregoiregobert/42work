#include "libft.h"
#include <stdio.h>

void	ft_printlst(t_list *lst)
{
	while (lst->next != 0)
	{
		printf("%d\n", lst->content);
		lst = lst->next;
	}
	printf("%d\n", lst->content);
}
