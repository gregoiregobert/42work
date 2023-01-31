#include "Cat.hpp"

//****************************************************//
//                                                    //
//               Constructor/Destructor               //
//                      Coplien                       //
//                                                    //
//****************************************************//

Cat::Cat()
{
	std::cout << "\033[1;33mCat\033[0m default constructor called" << std::endl;
	type = "\033[1;33mCat\033[0m";
}

Cat::Cat( const Cat& other )
{
	std::cout << "\033[1;33mCat\033[0m copy constructor called" << std::endl;
	type = other.type;
}

Cat	&Cat::operator=( const Cat& other )
{
	std::cout << "\033[1;33mCat\033[0m copy assignment called" << std::endl;
	type = other.type;
	return ( *this );
}

Cat::~Cat()
{
	std::cout << "\033[1;33mCat\033[0m destructor called" << std::endl;
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