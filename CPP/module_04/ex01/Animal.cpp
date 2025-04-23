#include "Animal.hpp"

//****************************************************//
//                                                    //
//               Constructor/Destructor               //
//                      Coplien                       //
//                                                    //
//****************************************************//

Animal::Animal() : type("")
{
	std::cout << "\033[1;32mAnimal\033[0m default constructor called" << std::endl;
}

Animal::Animal( const Animal& other )
{
	std::cout << "\033[1;32mAnimal\033[0m copy constructor called" << std::endl;
	type = other.type;
}

Animal &Animal::operator=( const Animal& other )
{
	std::cout << "\033[1;32mAnimal\033[0m copy assignment called" << std::endl;
	type = other.type;
	return ( *this );
}

Animal::~Animal()
{
	std::cout << "		\033[1;32mAnimal\033[0m destructor called" << std::endl;
}

//****************************************************//
//                                                    //
//                     Accessors                      //
//                                                    //
//****************************************************//

std::string	Animal::getType() const
{
	return (type);
}

//****************************************************//
//                                                    //
//                     Functions                      //
//                                                    //
//****************************************************//

void Animal::makeSound() const
{
	std::cout << "* Random animal sound *" << std::endl;
}

Brain	*Animal::getBrain() const
{
	return (0);
}