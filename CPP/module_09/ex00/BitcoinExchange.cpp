#include "BitcoinExchange.hpp"

//****************************************************//
//               Constructor/Destructor               //
//                      Coplien                       //
//****************************************************//

BitcoinExchange::BitcoinExchange()
{
	// std::cout << "BitcoinExchange constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange& other )
{
	*this = other;
}

BitcoinExchange::~BitcoinExchange()
{
	// std::cout << "BitcoinExchange destructor called" << std::endl;
}

BitcoinExchange	&BitcoinExchange::operator=( const BitcoinExchange &other )
{
	// std::cout << "BitcoinExchange copy constructor called" << std::endl;
	_Data = other._Data;
	return (*this);
}

//****************************************************//
//                    Accessor(s)                     //
//****************************************************//


void	BitcoinExchange::show_Data()
{
	for (std::map<std::string, std::string>::iterator it=_Data.begin(); it!=_Data.end(); ++it)
    std::cout << it->first << " => " << it->second << std::endl;
}

//****************************************************//
//                    Function(s)                     //
//****************************************************//

int BitcoinExchange::check_nb( std::string line )
{
	std::string tmp;
	int nb;

	tmp.append(line, 5, 2);
	std::istringstream iss(tmp);
	iss >> nb;
	if (nb > 12)
		return (1);
	
	tmp.erase();
	tmp.append(line, 8, 2);
	std::istringstream iss1(tmp);
	iss1 >> nb;
	if (nb > 31)
		return (1);

	tmp.erase();
	tmp.append(line, 13, line.size());
	std::istringstream iss2(tmp);
	iss2 >> nb;
	if (nb > 1000)
		throw BitcoinExchange::TooLarge();
	return (0);
}


int	BitcoinExchange::check_line( std::string line )
{
	int i = 0;
	const char *c = line.c_str();

	if ( (int)line.size() < 14 )
		return (1);

	if ( line.at(4) != '-' || line.at(7) != '-' ||
		line.at(10) != ' ' || line.at(11) != '|' || line.at(12) != ' ')
		return (1);

	while ( i < 4 )
		if ( !isdigit( c[i++] ) )
			return (1);

	i++;
	while ( i < 7 )
		if ( !isdigit( c[i++] ) )
			return (1);

	i++;
	while ( i < 10 )
		if ( !isdigit( c[i++] ) )
			return (1);

	i = 13;
	if (c[i] == '-')
		throw BitcoinExchange::NotPositive();

	while ( i < (int)line.size() && c[i] != '.' )
		if ( !isdigit( c[i++] ) )
			return (1);
	
	if ( c[i] == '.' && i+1 != (int)line.size())
		i++;

	while ( i < (int)line.size() )
		if ( !isdigit( c[i++] ) )
			return (1);

	if (check_nb(line) == 1)
		return (1);
	return (0);
}

void	BitcoinExchange::put_csv_in_map()
{
	std::string line;
	std::ifstream ifs("data.csv");
	if (ifs.fail())
		std::cout << "Error: could not open csv file." << std::endl;

	while ( std::getline( ifs, line ) )
		if ( (int)line.size() )
			_Data.insert( std::pair<std::string, std::string> (line.substr( 0, line.find(',') ),
						line.substr( line.find( "," ) + 1, line.size() ) ) );
}

void	BitcoinExchange::compare_to_csv( std::string line )
{
	std::map<std::string, std::string>::iterator it;

	it = _Data.lower_bound(  line.substr( 0,  10 ) );
	if (it != _Data.begin() && it != _Data.end() && line.substr( 0,  10 ).compare( it->first ) )
		it--;

	std::istringstream iss(line.substr( 13, line.size() ));
	std::istringstream iss2(it->second);
	float value_of_bitcoin;
	float nb_of_bitcoin;
	
	iss >> nb_of_bitcoin;
	iss2 >> value_of_bitcoin;
	
	std::cout << line.substr( 0, 10 ) << " => " << line.substr( 13, line.size() ) 
				<< " = " << value_of_bitcoin * nb_of_bitcoin << std::endl;
}