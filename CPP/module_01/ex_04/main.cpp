#include <iostream>
#include <fstream>

int	main(int ac, char **av)
{
	int	d;
	int	c;

	(void)ac;
	std::ifstream ifs(av[1]);
	ifs >> d >> c;

	std::cout << d << " " << std::endl;
}