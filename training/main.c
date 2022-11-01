#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "../libft/libft.h"

int	main()
{
	int	fd;

	fd = open("polo", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
	{
		printf("errno = %d\n", errno);
		perror(NULL);
		return (0);
	}
	close(fd);
	return (0);
}

