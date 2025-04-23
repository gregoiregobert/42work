#include "Brain.hpp"

//****************************************************//
//                                                    //
//               Constructor/Destructor               //
//                      Coplien                       //
//                                                    //
//****************************************************//

Brain::Brain()
{
	std::cout << "		\033[1;36mBrain\033[0m default constructor called" << std::endl;
}

Brain::Brain( const Brain& other )
{
	std::cout << "\033[1;36mBrain\033[0m copy constructor called" << std::endl;
	*this = other;
}

Brain	&Brain::operator=( const Brain& other )
{
	std::cout << "\033[1;36mBrain\033[0m copy assignment called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
	return ( *this );
}

Brain::~Brain()
{
	std::cout << "\033[1;36mBrain\033[0m destructor called" << std::endl;
}

//****************************************************//
//                                                    //
//                    Accessors                       //
//                                                    //
//****************************************************//

void	Brain::setIdea( std::string idea , int i )
{
	ideas[i] = idea;
}

std::string	Brain::getIdea( int i )
{
	return ( ideas[i] );
}
