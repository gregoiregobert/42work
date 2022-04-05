#include "../libft/libft.h"
#include <stdio.h>

int	toto(int index)
{
	return (index * index);
}

int	main()
{
	int	i = 0;
	int	koko;

	koko = toto(i);
	while (i++ < 10)
	{
		printf("%d\n", toto(i));
	}
	return 0;
}
