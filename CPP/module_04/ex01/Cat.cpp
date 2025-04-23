#include "Cat.hpp"

//****************************************************//
//                                                    //
//               Constructor/Destructor               //
//                      Coplien                       //
//                                                    //
//****************************************************//

Cat::Cat()
{
	std::cout << "	\033[1;33mCat\033[0m default constructor called" << std::endl;
	type = "\033[1;33mCat\033[0m";
	brain = new Brain();
}

Cat::Cat( const Cat& other )
{
	std::cout << "\033[1;33mCat\033[0m copy constructor called" << std::endl;
	type = other.type;
	brain = other.brain;
}

Cat	&Cat::operator=( const Cat& other )
{
	std::cout << "\033[1;33mCat\033[0m copy assignment called" << std::endl;
	type = other.type;
	brain = other.brain;
	return ( *this );
}

Animal	&Cat::operator=( const Animal& other )
{
	std::cout << "\033[1;33mAnimal\033[0m copy assignment called" << std::endl;
	type = other.getType();
	*brain = *(other.getBrain());
	return ( *this );
}

Cat::~Cat()
{
	delete brain;
	std::cout << "	\033[1;33mCat\033[0m destructor called" << std::endl;
}


//****************************************************//
//                                                    //
//                     Functions                      //
//                                                    //
//****************************************************//

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}

Brain *Cat::getBrain() const
{
	return ( brain );
}
