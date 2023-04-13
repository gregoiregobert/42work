#include "BitcoinExchange.hpp"


int	main(int ac, char ** av)
{
	BitcoinExchange Bitcoin;
	int ret;
	std::string line;

	if (ac != 2)
		std::cout << "Error: could not open file." << std::endl;

	std::ifstream ifs(av[1]);
	if (ifs.fail())
	{
		std::cout << "Error: could not open file." << std::endl;
		return (0);
	}

	while ( std::getline( ifs, line ) )
	{
		ret = Bitcoin.check_line( line );
		if ( !ret )
			std::cout << line << std::endl; // compare to map;
		else if ( ret == 1 )
			std::cerr << "Error: bad input => " << line << std::endl;
	}
	Bitcoin.put_csv_in_map();
}

