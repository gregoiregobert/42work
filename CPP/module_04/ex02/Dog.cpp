#include "Dog.hpp"

//****************************************************//
//                                                    //
//               Constructor/Destructor               //
//                      Coplien                       //
//                                                    //
//****************************************************//

Dog::Dog()
{
	std::cout << "	\033[1;34mDog\033[0m default constructor called" << std::endl;
	type = "\033[1;34mDog\033[0m";
	brain = new Brain();
}

Dog::Dog( const Dog& other )
{
	std::cout << "\033[1;34mDog\033[0m copy constructor called" << std::endl;
	type = other.type;
	brain = other.brain;
}

Dog	&Dog::operator=( const Dog& other )
{
	std::cout << "\033[1;34mDog\033[0m copy assignment called" << std::endl;
	type = other.type;
	brain = other.brain;
	return ( *this );
}

AAnimal	&Dog::operator=( const AAnimal& other )
{
	std::cout << "\033[1;33mAAnimal\033[0m copy assignment called" << std::endl;
	type = other.getType();
	*brain = *(other.getBrain());
	return ( *this );
}

Dog::~Dog()
{
	delete brain;
	std::cout << "	\033[1;34mDog\033[0m destructor called" << std::endl;
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

Brain *Dog::getBrain() const
{
	return ( brain );
}
