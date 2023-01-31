#include "WrongAnimal.hpp"

//****************************************************//
//                                                    //
//               Constructor/Destructor               //
//                      Coplien                       //
//                                                    //
//****************************************************//

WrongAnimal::WrongAnimal()
{
	std::cout << "\033[1;31mWrongAnimal\033[0m default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal& other )
{
	std::cout << "\033[1;31mWrongAnimal\033[0m copy constructor called" << std::endl;
	type = other.type;
}

WrongAnimal &WrongAnimal::operator=( const WrongAnimal& other )
{
	std::cout << "\033[1;31mWrongAnimal\033[0m copy assignment called" << std::endl;
	type = other.type;
	return ( *this );
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "\033[1;31mWrongAnimal\033[0m destructor called" << std::endl;
}

//****************************************************//
//                                                    //
//                     Accessors                      //
//                                                    //
//****************************************************//

std::string	WrongAnimal::getType() const
{
	return (type);
}

//****************************************************//
//                                                    //
//                     Functions                      //
//                                                    //
//****************************************************//

void WrongAnimal::makeSound() const
{
	std::cout << "* Strange sound i guess... *" << std::endl;
}