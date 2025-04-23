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

		//****************************************************//
		//               Constructor/Destructor               //
		//                      Coplien                       //
		//****************************************************//

		Array<T>()  : _n( 0 ), _array( 0 )
		{
			std::cout << "Empty  array constructor called" << std::endl;
		}

		Array<T>( unsigned int n ) : _n( n )
		{
			std::cout << "Array constructor called" << std::endl;
			_array = new T[_n];
		}

		~Array<T>()
		{
			std::cout << "Array destructor called" << std::endl;
			if (_array)
				delete [] _array;
		}

		Array<T>	&operator=( const Array& other )
		{
			std::cout << "Copy assginment called" << std::endl;
			if ( other._n > 0 )
			{
				_n = other._n;
				_array = new T[_n];
				for ( int i = 0; i < (int)_n; i++ )
					_array[i] = other._array[i];
			}
			else
			{
				_n = 0;
				_array = 0;
			}
			return (*this);
		}

		Array<T>( const Array& other )
		{
			std::cout << "Copy constructor called" << std::endl;
			*this = other;
		}

		//****************************************************//
		//                    Function(s)                     //
		//****************************************************//

		unsigned int	size()
		{
			return ( _n );
		}

		//****************************************************//
		//                      Operator                      //
		//****************************************************//

		T	&operator[]( size_t index )
		{
			if ( index >= _n )
				throw WrongIndex();
			else
				return ( _array[index] );
		}

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