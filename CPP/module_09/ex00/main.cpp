#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <cctype>
#include <boost/regex.hpp>

int check_date_format( char *c )
{
	while ( i < 4 )
		if ( !isdigit( c[i++] ) )
			return (1);

	if ( c[i++] != '-' )
		return (1);

	while ( i < 7 )
		if ( !isdigit( c[i++] ) )
			return (1);

	if ( c[i++] != '-' )
		return (1);

	while ( i < 10 )
		if ( !isdigit( c[i++] ) )
			return (1);

	if ( c[i++] != ' ' )
		return (1);
}

int	check_line( std::string line )
{
	int i = 0;
	const char *c = line.c_str();


	return (0);
}

int	main(int ac, char ** av)
{
	std::string line;
	std::queue<std::string> array;

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
		if ( !check_line( line ) )
			array.push( line );
	}
	while ( array.size() )
	{
		std::cout << array.front() << std::endl;
		array.pop();
	}
}

