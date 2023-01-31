#include "Form.hpp"

//****************************************************//
//                                                    //
//               Constructor/Destructor               //
//                      Coplien                       //
//                                                    //
//****************************************************//

Form::Form()
: _name("unknown") , _lowestGrade_toSign( _lowestGrade ), _highestGrade_toSign( _highestGrade )
{
	std::cout << "\033[1;36mForm\033[0m default constructor called" << std::endl;
}

Form::Form( std::string name , int lowestGrade , int highestGrade)
: _name( name ) , _lowestGrade_toSign( lowestGrade ) , _highestGrade_toSign( highestGrade )
{
	std::cout << "\033[1;36mForm\033[0m constructor called" << std::endl;
}

Form::Form( const Form& other )
{
	std::cout << "\033[1;36mForm\033[0m copy constructor called" << std::endl;
	_name = other._name;
	_signed = other._signed;
}

Form &Form::operator=( const Form& other )
{
	std::cout << "\033[1;36mForm\033[0m copy assignment called" << std::endl;
	_name = other._name;
	_signed = other._signed;
	return ( *this );
}

Form::~Form()
{
	std::cout << "\033[1;36mForm\033[0m destructor called" << std::endl;
}

//****************************************************//
//                                                    //
//                    Accessors                       //
//                                                    //
//****************************************************//

std::string	Form::getName() const
{
	return ( _name );
}

bool		Form::getSigned() const
{
	return ( _signed );
}

int			Form::getLowestGrade_toSign() const
{
	return ( _lowestGrade_toSign );
}

int			Form::getHighestGrade_toSign() const
{
	return ( _highestGrade_toSign );
}

//****************************************************//
//                                                    //
//                    Functions                       //
//                                                    //
//****************************************************//

void	Form::checkGrade_toSign() const
{
	if ( _lowestGrade_toSign > _lowestGrade )
		throw Form::GradeTooLowException();
	if ( _highestGrade_toSign < _highestGrade )
		throw Form::GradeTooHighException();
	if ( _lowestGrade_toSign < _highestGrade_toSign)
		throw Form::GradeDifference();
}

//****************************************************//
//                                                    //
//                     No-member                      //
//                                                    //
//****************************************************//

std::ostream &operator<<( std::ostream &out , const Form& value)
{
	out << Form::getName << "have to be sign by a bureaucrat "
}