#include "Dog.hpp"

//****************************************************//
//                                                    //
//               Constructor/Destructor               //
//                      Coplien                       //
//                                                    //
//****************************************************//

Dog::Dog()
{
	std::cout << "\033[1;34mDog\033[0m default constructor called" << std::endl;
	type = "\033[1;34mDog\033[0m";
}

Dog::Dog( const Dog& other )
{
	std::cout << "\033[1;34mDog\033[0m copy constructor called" << std::endl;
	type = other.type;
}

Dog	&Dog::operator=( const Dog& other )
{
	std::cout << "\033[1;34mDog\033[0m copy assignment called" << std::endl;
	type = other.type;
	return ( *this );
}

Dog::~Dog()
{
	std::cout << "\033[1;34mDog\033[0m destructor called" << std::endl;
}

//****************************************************//
//                                                    //
//                     Functions                      //
//                                                    //
//****************************************************//

void Dog::makeSound() const
{
	std::cout << "Wouf" << std::endl;
}