#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "../libft/libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}


double	ft_atof(char *str)
{
	int		i;
	int		pos;
	float	j;
	float	ret;

	i = 0;
	j = 0.1;
	ret = 0;
	pos = 1;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		i++;
		pos = -1;
	}
	while (ft_isdigit(str[i]))
		ret = ret * 10 + (str[i++] - '0');
	if (str[i] && str[i] == '.')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		ret += (str[i++] - '0') * j;
		j *= 0.1;
	}
	return (ret * pos);
}

int	main()
{
	char	a[5] = "1.3";
	float	b = 1.3;

	printf("a = %f\nb = %f\n", ft_atof(a), b);
	return (0);
}
