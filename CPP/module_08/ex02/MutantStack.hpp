#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

template< class T>
class MutantStack : public std::stack<T>
{
	public:

		MutantStack<T>(void) { return ; }
		MutantStack<T>( const MutantStack& other) { *this = other; }
		~MutantStack<T>( void ) { return ; }

		MutantStack<T> &operator=( const MutantStack& other )
		{
			(void)other;
			return (*this);
		}

		typedef typename std::stack<T>::container_type::iterator it;
		
		it	begin( void ) { return this->c.begin(); }
		it	end( void ) { return this->c.end(); }
};

#endif