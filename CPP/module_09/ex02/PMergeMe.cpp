#include "PMergeMe.hpp"

//****************************************************//
//               Constructor/Destructor               //
//                      Coplien                       //
//****************************************************//

PMergeMe::PMergeMe( int ac, char **av ) : _ac(ac) ,_av(av)
{
	// std::cout << "PMergeMe constructor called" << std::endl;
	if (ac < 3)
		throw PMergeMe::NoArg();
	put_in_array();
}

PMergeMe::PMergeMe( const PMergeMe& other )
{
	*this = other;
}

PMergeMe::~PMergeMe()
{
	// std::cout << "PMergeMe destructor called" << std::endl;
}

PMergeMe	&PMergeMe::operator=( const PMergeMe &other )
{
	// std::cout << "PMergeMe copy constructor called" << std::endl;
	(void)other;
	return (*this);
}

//****************************************************//
//                    Accessor(s)                     //
//****************************************************//


//****************************************************//
//                    Function(s)                     //
//****************************************************//

void	PMergeMe::put_in_array()
{
	for (int i = 1; i < _ac; i++)
	{
		std::atoi(_av[i]);
	}
}
