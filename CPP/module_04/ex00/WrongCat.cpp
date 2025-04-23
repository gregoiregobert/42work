#include "WrongCat.hpp"

//****************************************************//
//                                                    //
//               Constructor/Destructor               //
//                      Coplien                       //
//                                                    //
//****************************************************//

WrongCat::WrongCat()
{
	std::cout << "\033[1;31mWrongCat\033[0m default constructor called" << std::endl;
	type = "\033[1;31mWrongCat\033[0m";
}

WrongCat::WrongCat( const WrongCat& other )
{
	std::cout << "\033[1;31mWrongCat\033[0m copy constructor called" << std::endl;
	type = other.type;
}

WrongCat	&WrongCat::operator=( const WrongCat& other )
{
	std::cout << "\033[1;31mWrongCat\033[0m copy assignment called" << std::endl;
	type = other.type;
	return ( *this );
}

WrongCat::~WrongCat()
{
	std::cout << "\033[1;31mWrongCat\033[0m destructor called" << std::endl;
}
