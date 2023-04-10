#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>

class BitcoinExchange
{
	private:

	
	public:

		BitcoinExchange();
		BitcoinExchange( const BitcoinExchange& other );
		~BitcoinExchange();

		BitcoinExchange &operator=( const BitcoinExchange& other);
};

std::ostream &operator<<(std::ostream &out, BitcoinExchange &value);

#endif