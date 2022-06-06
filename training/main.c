#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "../libft/libft.h"
#include <unistd.h>

int	main(int ac, char **av, char **ev)
{
	int		i;
	char	**path;
	
	i = -1;
	(void)ac;
	(void)av;
	while (ev[++i])
		if (ft_strncmp("PATH", ev[i], 4) == 0)
			path = ft_split(ev[i], ':');
	i = 0;
	while (path[++i])
		printf("%s\n", path[i]);
	if (access("/usr/bin/ls", X_OK) == -1)
		write(1, "nop\n", 4);
	else
		write(1, "find it\n", 8);
}
