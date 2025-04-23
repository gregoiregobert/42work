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
	_input = other._input;
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

	for (int i = 0; i < (int)_input.size(); i++)
	{
		if (i % 2 == 1)
		{
			if (_input.at(i) != ' ')
				throw BadInput();
		}
		else 
			if (_input.at(i) == ' ')
				throw BadInput();
	} 
}

void	RPN::calculation()
{

	for ( int i = 0; i < (int)_input.size(); i++ )
	{
		if ( isdigit( _input.at(i) ) )
			_stack.push_front( _input.at(i) - '0' );
		else if ( !isdigit( _input.at(i) ) && _input.at(i) != ' ')
			operation_manager( _input.at(i) );
	}

	if (_stack.size() != 1 )
		throw BadInput();

	std::cout << _stack.front() << std::endl;
}

void	RPN::operation_manager( char c )
{
	void ( RPN::*fct[] )() = {&RPN::addition, &RPN::soustraction, &RPN::multiply, &RPN::division};

	std::string operand = "+-*/";

	if ( _stack.size() < 2 )
		throw BadInput();

	
	for ( int i = 0; i < (int)operand.size(); i++ )
		if ( operand.at(i) == c )
			(this->*fct[i])();
	
}

// ******** OPERATION ******* //

void	RPN::addition()
{
	int a;
	int b;

	a = _stack.front();
	_stack.pop_front();

	b = _stack.front();
	_stack.pop_front();

	_stack.push_front(b + a);
}

void	RPN::soustraction()
{
	int a;
	int b;

	a = _stack.front();
	_stack.pop_front();

	b = _stack.front();
	_stack.pop_front();
	
	_stack.push_front(b - a);
}

void	RPN::multiply()
{
	int a;
	int b;

	a = _stack.front();
	_stack.pop_front();

	b = _stack.front();
	_stack.pop_front();
	
	_stack.push_front(b * a);
}

void	RPN::division()
{
	int a;
	int b;

	a = _stack.front();
	_stack.pop_front();

	b = _stack.front();
	_stack.pop_front();

	if ( a == 0 )
		throw ZeroDiv();
	
	_stack.push_front(b / a);
}