#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <stdexcept>
#include <iostream>

class NotFound : public std::exception{
	public:
		virtual const char* what() const throw(){
			return ("\033[1;31moccurrence not found\033[0m");
		}
};

template<class T>
void	easyfind(T cont, int search)
{
	throw NotFound();
}

#endif