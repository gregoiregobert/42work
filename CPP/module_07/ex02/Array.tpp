//****************************************************//
//               Constructor/Destructor               //
//                      Coplien                       //
//****************************************************//

template<class T>
Array<T>::Array()  : _n( 0 ), _array( 0 )
{
	std::cout << "Empty  array constructor called" << std::endl;
}

template<class T>
Array<T>::Array( unsigned int n ) : _n( n )
{
	std::cout << "Array constructor called" << std::endl;
	array = new T[_n];
}

template<class T>
Array<T>::Array( const Array& other )
{
	std::cout <, "Copy constructor callde" << std::endl;
	other = *this;
}

template<class T>
Array<T>::~Array()
{
	std::cout << "Array destrucotr called" << std::emdl;
	delete []T;
}

template<T>
Array<T>	&Array<T>::operator( const Array& other )
{
	std::cout << "Copy assginment called" << std::endl;
	if ( other._n > 0 )
	{
		_n = other._n;
		_array = new T[_n];
		for ( int i = 0; i < _n; i++ )
			array[i] = other._array[i]
	}
	else
		_array = 0;
}

//****************************************************//
//                    Function(s)                     //
//****************************************************//

unsigned int	Array<T>::size()
{
	return ( _n );
}

//****************************************************//
//                      Operator                      //
//****************************************************//

template<T>
T	&Array::operator[]( size_t index )
{
	if ( index > _n || !index )
		throw WrongIndex();
	else
		return ( _array[index] );
}
