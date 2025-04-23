#ifndef AANIMAL_H
# define AANIMAL_H

#include <iostream>
#include <new>
#include "Brain.hpp"

class AAnimal
{
	protected:

		std::string	type;

	public:

		AAnimal();
		AAnimal( const AAnimal& other);
		virtual ~AAnimal();

		virtual AAnimal &operator=(const AAnimal& other);

		virtual void	makeSound() const = 0;
		std::string		getType() const;
		virtual Brain	*getBrain() const = 0;
};

#endif