#ifndef ANIMAL_H
# define ANIMAL_H

#include <iostream>
#include <new>
#include "Brain.hpp"

class Animal
{
	protected:

		std::string	type;

	public:
		
		Animal();
		Animal( const Animal& other);
		virtual ~Animal();

		virtual Animal &operator=(const Animal& other);

		virtual void	makeSound() const;
		std::string		getType() const;
		virtual Brain	*getBrain() const;
};

#endif