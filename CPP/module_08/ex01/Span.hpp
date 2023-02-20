#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <cstdlib>

class Span
{
	private:

		unsigned int		_N;
		unsigned int		_manyAdd;
	
	public:

		std::vector<int>	_nb;
		Span( unsigned int N );
		Span( const Span& other );
		~Span();

		Span &operator=( const Span& other);

		void	addNumber( int nb );
		void	addNumber( std::vector<int>::iterator begin, std::vector<int>::iterator end );
		void	addRandom();
		int		shortestSpan();
		int		longestSpan();

		unsigned int	get_manyAdd();
		std::vector<int>::iterator	getNb_it_begin();

		class maxReached : public std::exception{
			public:
			virtual const char* what() const throw(){
				return ("\033[1;31mMaximum size has been reached(or will be overfill)\033[0m");
			}
		};
		
		class notEnough : public std::exception{
			public:
			virtual const char* what() const throw(){
				return ("\033[1;31mNot enough number to make a comparaison\033[0m");
			}
		};
};

std::ostream &operator<<(std::ostream &out, Span &value);

#endif
