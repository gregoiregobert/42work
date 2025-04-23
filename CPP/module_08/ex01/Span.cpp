#include "Span.hpp"

//****************************************************//
//               Constructor/Destructor               //
//                      Coplien                       //
//****************************************************//

Span::Span( unsigned int N ) : _N( N )
{
	// std::cout << "Span constructor called" << std::endl;
	_manyAdd = 0;
}

Span::Span( const Span& other )
{
	*this = other;
}

Span::~Span()
{
	// std::cout << "Span destructor called" << std::endl;
}

Span	&Span::operator=( const Span &other )
{
	// std::cout << "Span copy constructor called" << std::endl;
	_N = other._N;
	if (_N)
	{
		for (int i = 0; i < (int)_N; i++)
			_nb[i] = other._nb[i];
	}
	return (*this);
}

//****************************************************//
//                    Accessor(s)                     //
//****************************************************//

std::vector<int>::iterator	Span::getNb_it_begin()
{
	return (_nb.begin() );
}

unsigned int	Span::get_manyAdd()
{
	return ( _manyAdd );
}

//****************************************************//
//                    Function(s)                     //
//****************************************************//

void	Span::addNumber( int nb )
{

	if (_manyAdd < _N)
	{	
		_manyAdd++;
		_nb.push_back(nb);
	}
	else
		throw maxReached();
}

void	Span::addNumber( std::vector<int>::iterator begin, std::vector<int>::iterator end )
{
	std::vector<int>::iterator it;

	it = _nb.end();
	while (begin != end)
	{
		_manyAdd++;
		if ( _manyAdd > _N )
			throw maxReached();
		_nb.push_back(*begin++);
	}
}

int	Span::shortestSpan()
{
	int	shortest;

	if ( _manyAdd < 2 )
		throw notEnough();
	std::sort(_nb.begin(), _nb.end());
	std::vector<int>::iterator it = _nb.begin();
	shortest = it[1] - it [0];
	for (int i = 0; i < (int)_nb.size() - 1; i++)
		if (it[i + 1] - it [i] < shortest)
			shortest = it[i + 1] - it [i];
	return (shortest);
}

int	Span::longestSpan()
{
	int max;
	int min;
	int longest;

	if ( _manyAdd < 2 )
		throw notEnough();
	max = *std::max_element(_nb.begin(), _nb.end());
	min = *std::min_element(_nb.begin(), _nb.end());
	longest = max - min;
	return (longest);
}

void	Span::addRandom()
{
	srand( time(0) );
	for ( int i = (int)_nb.size(); i < (int)_N; i++ )
	{
		_manyAdd++;
		_nb.push_back(rand());
	}
}

//****************************************************//
//                    No_member(s)                     //
//****************************************************//

std::ostream &operator<<(std::ostream &out, Span &value)
{
	std::vector<int>::iterator it = value.getNb_it_begin();

	for (int i = 0; i < (int)value.get_manyAdd(); i++)
	{
		out << *it << ' ';
		it++;
	}

    return (out);
}