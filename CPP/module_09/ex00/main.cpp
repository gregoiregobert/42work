#include "BitcoinExchange.hpp"


int	main(int ac, char ** av)
{
	BitcoinExchange Bitcoin;
	int ret;
	std::string line;

	if (ac != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return (0);
	}

	std::ifstream ifs(av[1]);
	if (ifs.fail())
	{
		std::cout << "Error: could not open file." << std::endl;
		return (0);
	}

	Bitcoin.put_csv_in_map();
	while ( std::getline( ifs, line ) )
	{
		if (!line.size() )
			continue;
		try{
			ret = Bitcoin.check_line( line );
			if ( !ret )
				Bitcoin.compare_to_csv( line );
			else if ( ret == 1 )
				std::cerr << "\033[1;31mError: bad input => \033[0m" << line << std::endl; 
		}
		catch(std::exception &e){
			std::cerr << e.what() << std::endl;
		}
	}
}

