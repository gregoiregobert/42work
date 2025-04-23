#ifndef RPN_HPP
# define RPN_HPP

#include <deque>
#include <iostream>
#include <cctype>
#include <cstddef>

class RPN
{
	private:

		int	_ac;
		char **_av;
		std::string _input;
		std::deque<int> _stack;

	public:

		RPN( int ac, char **av );
		RPN( const RPN& other );
		~RPN();

		RPN &operator=( const RPN& other);

		void	check_input();
		void	calculation();
		void	operation_manager( char c );
		void	addition();
		void	soustraction();
		void	multiply();
		void	division();


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

		class BadInput : public std::exception{
			public:
			virtual const char* what() const throw(){
				return ("\033[1;31mError: Bad input.\033[0m");
			}
		};

		class ZeroDiv : public std::exception{
			public:
			virtual const char* what() const throw(){
				return ("\033[1;31mError: Division by 0 is a paradoxe.\033[0m");
			}
		};
};

#endif