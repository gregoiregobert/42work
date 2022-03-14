#include "../libft/libft.h"

int	main()
{
	t_list	*list;
	char	*str = "123456789";

	list = 0;
	while (*str)
		ft_lstadd_back(&list, ft_lstnew(ft_atoi(str++)));
	ft_printlst(list);
	return 0;
}
