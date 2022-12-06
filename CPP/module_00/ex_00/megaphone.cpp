#include <iostream>

std::string	upper_case(char *str)
{
	int			i;

	i = -1;
	while (str[++i])
		str[i] = toupper(str[i]);
	return (str);
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (++i < ac)
			std::cout << upper_case(av[i]);
		std::cout << std::endl;
	}
}
