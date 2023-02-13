#include "Analyst.hpp"
#include "Utils.hpp"
 
//****************************************************//
//                                                    //
//               Constructor/Destructor               //
//                      Coplien                       //
//                                                    //
//****************************************************//

Analyst::Analyst( std::string input )
: _input( input )
{
	// std::cout << "\033[1;33mAnalyst\033[0m constructor called" << std::endl;
}

Analyst::Analyst()
{
	// std::cout << "Default \033[1;33mAnalyst\033[0m constructor called" << std::endl;
}

Analyst::Analyst( const Analyst& other )
{
	// std::cout << "\033[1;33mAnalyst\033[0m Copy constructor called" << std::endl;
	*this = other;
}

Analyst::~Analyst()
{
	// std::cout << "\033[1;33mAnalyst\033[0m destructor called" << std::endl;
}

Analyst &Analyst::operator=( const Analyst& other )
{
	// std::cout << "\033[1;33mAnalyst\033[0m copy assignment called" << std::endl;
	_input = other._input;
	return ( *this );
}

//****************************************************//
//                                                    //
//                    Functions                       //
//                                                    //
//****************************************************//

void	Analyst::detect_type()
{
	if (!special_character())
	{
		check_input();
		is_char();
		is_int();
		is_double();
		is_float();
	}
}

/***** Error syntaxe *****/

void	Analyst::check_input() const
{
	if (_input.length() > 1 && !str_syntaxe(_input))
		throw Analyst::Not_a_number_Not_a_char();
}

bool	Analyst::str_syntaxe( std::string str ) const
{
	int x;
	int i;

	i = 0;
	x = str[i];
	if (str[i] != '-' && !isdigit(x))
		return (0);
	while (++i < (int)str.length() && str[i] != '.' && str[i] != 'f')
	{
		x = str[i];
		if (!isdigit(x))
			return (0);
	}
	while (++i < (int)str.length() && str[i] != 'f')
	{
		x = str[i];
		if (!isdigit(x))
			return (0);
	}
	if (++i < (int)str.length())
		return (0);
	return (1);
}

/***** Special ******/

bool	Analyst::special_character() const
{
	std::string	special[] = {"nan", "-inf", "+inf", "nanf", "-inff", "+inff"};

	for (int i = 0; i < 3; i++){
		if (_input == special[i]){
			print_special_double( special[i] );
			return (true);
		}
	}

	for (int i = 3; i < 6; i++){
		if ( _input == special[i] ){
			print_special_float( special[i] );
			return (true);
		}
	}
	return (false);
}

void	Analyst::print_special_double( std::string spe ) const
{
	std::cout << "char :		impossible" << std::endl;
	std::cout << "int :		impossible" << std::endl;
	std::cout << "double :	" << spe << std::endl;
	std::cout << "float :		" << spe << "f" << std::endl;
}

void	Analyst::print_special_float( std::string spe ) const
{
	std::string spe_f = spe;

	std::cout << "char :		impossible" << std::endl;
	std::cout << "int :		impossible" << std::endl;
	std::cout << "double :	" << spe.erase(spe.length() - 1) << std::endl;
	std::cout << "float :		" << spe_f << std::endl;
}

/***** Conversion ******/

void	Analyst::is_char() const
{
	char c = _input[0];

	if (_input.length() > 1 || isdigit(_input[0]))
		return ;
	std::cout << "char :		'" << _input[0] << "'" << std::endl;
	std::cout << "int :		" << static_cast<int>(c) << std::endl;
	std::cout << "double :	" << static_cast<double>(c) << ".0" << std::endl;
	std::cout << "float :		" << static_cast<float>(c) << ".0f" << std::endl;
	throw End();
}

void	Analyst::is_int() const
{
	if (is_dot(_input) || int_overflow( _input ))
		return ;

	int	x;

	x = atoi(_input.c_str());
	if (x > 31 && x < 127)
		std::cout << "char :		'" << static_cast<char>(x) << "'" << std::endl;
	else
		std::cout << "char :		non printable character" << std::endl;
	std::cout << "int :		" << x << std::endl;
	std::cout << "double :	" << static_cast<double>(x) << ".0" << std::endl;
	std::cout << "float :		" << static_cast<float>(x) << ".0f" << std::endl;
	throw End();
}

void	Analyst::is_double() const
{
	if (is_f(_input))
		return ;

	std::istringstream ss(_input);
	double d;

	ss >> d;
	if (d > 31 && d < 127)
		std::cout << "char :		'" << static_cast<char>(d) << "'" << std::endl;
	else
		std::cout << "char :		Non printable character" << std::endl;

	print_int(d);
	print_double(d);
	print_float(d);
	throw End();
}

void	Analyst::is_float() const
{
	std::istringstream ss(_input);
	float f;

	ss >> f;

	if (f > 31 && f < 127)
		std::cout << "char :		'" << static_cast<char>(f) << "'" << std::endl;
	else
		std::cout << "char :		Non printable character" << std::endl;

	print_int(f);
	print_double(f);
	print_float(f);
	throw End();
}

/***** Print ******/

void	Analyst::print_int( double d ) const
{
	if (int_overflow(_input))
		std::cout << "int :		overflow" << std::endl;
	else
		std::cout << "int :		" << static_cast<int>(d) << std::endl;
}

void	Analyst::print_int( float f ) const
{
	if (int_overflow(_input))
		std::cout << "int :		overflow" << std::endl;
	else
		std::cout << "int :		" << static_cast<int>(f) << std::endl;
}

void	Analyst::print_float( double d ) const
{
	if (float_overflow( _input ))
		std::cout << "float :		overflow" << std::endl;
	else if (is_integer(_input))
		std::cout << "float :		" << static_cast<float>(d) << ".0f" << std::endl;
	else
		std::cout << "float :		" << static_cast<float>(d) << "f" << std::endl;
}

void	Analyst::print_float( float f ) const
{
	if (float_overflow( _input ))
		std::cout << "float :		overflow" << std::endl;
	else if (is_integer(_input))
		std::cout << "float :		" << f << ".0f" << std::endl;
	else
		std::cout << "float :		" << f << "f" << std::endl;
}

void	Analyst::print_double( double d ) const
{
	if (double_overflow(_input))
		std::cout << "double :	overflow" << std::endl;
	else if (is_integer(_input))
		std::cout << "double :	" << d << ".0" << std::endl;
	else
		std::cout << "double :	" << d << std::endl;
}

void	Analyst::print_double( float f ) const
{
	if (double_overflow(_input))
		std::cout << "double :		overflow" << std::endl;
	else if (is_integer(_input))
		std::cout << "double :	" << static_cast<double>(f) << ".0" << std::endl;
	else
		std::cout << "double :	" << static_cast<double>(f) << std::endl;
}