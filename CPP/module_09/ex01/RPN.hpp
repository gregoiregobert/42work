#ifndef RPN_HPP
# define RPN_HPP

#include <queue>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <cstddef>

class RPN
{
	private:

		int	_ac;
		char **_av;
		std::string _input;
		std::queue<char> _stack;

	public:

		RPN( int ac, char **av );
		RPN( const RPN& other );
		~RPN();

		RPN &operator=( const RPN& other);

		void	check_input();
		void	RPN::calculation();

		class TooManyArg : public std::exception{
			public:
			virtual const char* what() const throw(){
				return ("\033[1;31mError: too many arg.\033[0m");
			}
		};

		class WrongChar : public std::exception{
			public:
			virtual const char* what() const throw(){
				return ("\033[1;31mError: Non-expecting character.\033[0m");
			}
		};

		class BadFormat : public std::exception{
			public:
			virtual const char* what() const throw(){
				return ("\033[1;31mError: Bad input.\033[0m");
			}
		};
};

#endif