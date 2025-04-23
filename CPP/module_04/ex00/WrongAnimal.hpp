#ifndef WrongAnimal_H
# define WrongAnimal_H

#include <iostream>

class WrongAnimal
{
	protected:

		std::string	type;

	public:
		
		WrongAnimal();
		WrongAnimal( const WrongAnimal& other);
		virtual ~WrongAnimal();

		WrongAnimal &operator=(const WrongAnimal& other);
		
		void makeSound() const;

		std::string getType() const;
};

#endif