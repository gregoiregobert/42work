#include "RPN.hpp"

//****************************************************//
//               Constructor/Destructor               //
//                      Coplien                       //
//****************************************************//

RPN::RPN( int ac, char **av ) : _ac(ac), _av(av)
{
	// std::cout << "RPN constructor called" << std::endl;
	if (ac != 2)
		throw RPN::TooManyArg();
	_input = av[1];
	check_input();
	calculation();
}

RPN::RPN( const RPN& other )
{
	*this = other;
}

RPN::~RPN()
{
	// std::cout << "RPN destructor called" << std::endl;
}

RPN	&RPN::operator=( const RPN &other )
{
	// std::cout << "RPN copy constructor called" << std::endl;
	_ac = other._ac;
	_av = other._av;
	_stack = other._stack;
	return (*this);
}

//****************************************************//
//                    Accessor(s)                     //
//****************************************************//


//****************************************************//
//                    Function(s)                     //
//****************************************************//

void	RPN::check_input()
{
	std::size_t found = _input.find_first_not_of( "0123456789/*-+ " );
	if (found != std::string::npos)
		throw RPN::WrongChar();

	char *char_input = _av[1];
	for (int i = 0; i < (int)_input.size(); i++)
	{
		if (i % 2 == 1)
		{
			if (char_input[i] != ' ')
				throw BadFormat();
		}
		else 
			if (char_input[i] == ' ')
				throw BadFormat();
	}
}

void	RPN::calculation()
{
	
}