#include "../libft/libft.h"
#include <stdio.h>

int	main()
{
	int	i = 0;
	int	j = 10;
	int	dif;
	int	bestdif;

	while (i++ < 15)
	{
		dif = j - i;

		if (dif < 5)
			if (dif > -2)
				bestdif = dif;
		printf("%d\n", bestdif);
	}
}
