#include "AAnimal.hpp"

//****************************************************//
//                                                    //
//               Constructor/Destructor               //
//                      Coplien                       //
//                                                    //
//****************************************************//

AAnimal::AAnimal() : type("")
{
	std::cout << "\033[1;32mAAnimal\033[0m default constructor called" << std::endl;
}

AAnimal::AAnimal( const AAnimal& other )
{
	std::cout << "\033[1;32mAnimal\033[0m copy constructor called" << std::endl;
	type = other.type;
}

AAnimal &AAnimal::operator=( const AAnimal& other )
{
	std::cout << "\033[1;32mAnimal\033[0m copy assignment called" << std::endl;
	type = other.type;
	return ( *this );
}

AAnimal::~AAnimal()
{
	std::cout << "		\033[1;32mAAnimal\033[0m destructor called" << std::endl;
}

//****************************************************//
//                                                    //
//                     Accessors                      //
//                                                    //
//****************************************************//

std::string	AAnimal::getType() const
{
	return (type);
}

//****************************************************//
//                                                    //
//                     Functions                      //
//                                                    //
//****************************************************//

void AAnimal::makeSound() const
{
	std::cout << "* Random animal sound *" << std::endl;
}