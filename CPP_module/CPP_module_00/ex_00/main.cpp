#include <iostream>
#include "megaphone.cpp"

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
