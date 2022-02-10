#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int 	fd;
	char	*s;
	int		i;

	i = 0;
	fd = open("fichier.txt", O_RDONLY);
	if (fd < 0)
		return (0);
	while (i < 5)
	{
		s = get_next_line(fd);
		printf("%s", s);
		free(s);
		i++;
	}
	system("leaks a.out");	
}
