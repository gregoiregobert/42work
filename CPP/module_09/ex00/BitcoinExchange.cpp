#include "BitcionExchange.hpp"

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
	_N = other._N;
	return (*this);
}

//****************************************************//
//                    Accessor(s)                     //
//****************************************************//


//****************************************************//
//                    Function(s)                     //
//****************************************************//




//****************************************************//
//                    No_member(s)                     //
//****************************************************//

// std::ostream &operator<<(std::ostream &out, Span &value)
// {
// 	std::vector<int>::iterator it = value.getNb_it_begin();

// 	for (int i = 0; i < (int)value.get_manyAdd(); i++)
// 	{
// 		out << *it << ' ';
// 		it++;
// 	}

//     return (out);
// }