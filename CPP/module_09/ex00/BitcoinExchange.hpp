#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>

class BitcoinExchange
{
	private:

		std::map<std::string, std::string> _Data;

	public:

		BitcoinExchange();
		BitcoinExchange( const BitcoinExchange& other );
		~BitcoinExchange();

		BitcoinExchange &operator=( const BitcoinExchange& other);

		int		check_nb( std::string line );
		int		check_line( std::string line );
		void	put_csv_in_map();
		void	show_Data();
		void	compare_to_csv( std::string line );
				
		class TooLarge : public std::exception{
			public:
			virtual const char* what() const throw(){
				return ("\033[1;31mError: too large number.\033[0m");
			}
		};

		class BadInput : public std::exception{
			public:
			virtual const char* what() const throw(){
				return ("\033[1;31mError: bad input => \033[0m");
			}
		};

		class NotPositive : public std::exception{
			public:
			virtual const char* what() const throw(){
				return ("\033[1;31mError: not a positive number.\033[0m");
			}
		};
};

#endif