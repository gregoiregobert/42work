#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <cctype>

int	check_line( std::string line )
{
	std::string tmp;
	int nb;
	int i = 0;
	const char *c = line.c_str();

	while ( i < 4 )
		if ( !isdigit( c[i++] ) )
			return (1);

	if ( c[i++] != '-' )
		return (1);

	while ( i < 7 )
		if ( !isdigit( c[i++] ) )
			return (1);
	tmp.append(line, 5, 2);
	std::istringstream iss(tmp);
	iss >> nb;
	if (nb > 12)
		return (1);

	if ( c[i++] != '-' )
		return (1);

	while ( i < 10 )
		if ( !isdigit( c[i++] ) )
			return (1);

	if ( c[i++] != ' ' || c[i++] != '|' || c[i++] != ' ')
		return (1);

	if ( c[i++] == '-' )
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return (2);
	}

	while ( i < (int)line.size() && c[i] != '.' )
		if ( !isdigit( c[i++] ) )
			return (1);
	
	if ( c[i] == '.' && i+1 != (int)line.size())
		i++;

	while ( i < (int)line.size() )
		if ( !isdigit( c[i++] ) )
			return (1);

	return (0);
}

int	main(int ac, char ** av)
{
	int ret;
	std::string line;
	std::queue<std::string> queue;

	if (ac != 2)
		std::cout << "Error: could not open file." << std::endl;

	std::ifstream ifs(av[1]);
	if (ifs.fail())
	{
		std::cout << "Error: could not open file." << std::endl;
		return (0);
	}

	while ( std::getline( ifs, line ) )
		queue.push( line );

	while ( queue.size() )
	{
		ret = check_line( queue.front() );
		if ( !ret )
			std::cout << queue.front() << std::endl;
		else if ( ret == 1 )
			std::cerr << "Error: bad input => " << queue.front() << std::endl;
		queue.pop();
	}
}

