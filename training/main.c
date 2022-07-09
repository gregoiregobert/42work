#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

int	ft_strlen(char *s)
{
	int i;

	i = 0;
	while(*s++)
		i++;
	return (i);
}

int	main(int ac, char **av)
{
	printf("%s\n",av[1] + (ft_strlen(av[1]) - 3));
}

