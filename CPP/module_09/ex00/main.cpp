#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>

int	main(int av, char ** ac)
{
	if (av != 2)
		std::cout << "Error: could not open file." << std::endl;

	std::ifstream ifs(av[1]);
	if (ifs.fail())
	{
		std::cout << "Error: could not open file." << std::endl;
		return (0);
	}
	
}