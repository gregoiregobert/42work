#include "../libft/libft.h"
#include <stdio.h>

int	main()
{
	char *pote;

	pote = malloc(sizeof(char) * 6);
	pote = "12345";
	while (*pote)
	{
		while ((*pote)-- > 0)
			printf("%c\n", *pote);
		pote++;
	}
}
