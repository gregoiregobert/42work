#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <stdexcept>

template<class T>
class Array
{
	private:

		unsigned int	_n;
		T				*_array;

	public:

		Array();
		Array( unsigned int n );
		Array( const Array& other );
		~Array();

		Array &operator=( const Array& other );
		T &operator[]( size_t index );

		unsigned int	size();

	/******************************/
	/*        Exception(s)        */
	/******************************/

	class WrongIndex : public std::exception{
		public:
			virtual const char* what() const throw(){
				return ("\033[1;31mError : index does not exist\033[0m");
			}
	};
};

#endif