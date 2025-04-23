#include "Form.hpp"

//****************************************************//
//                                                    //
//               Constructor/Destructor               //
//                      Coplien                       //
//                                                    //
//****************************************************//

Form::Form()
: _name("unknown") , _lowestGrade_toSign( _lowestGrade ), _lowestGrade_toExec( _lowestGrade )
{
	checkGrade_toSign();
	std::cout << "\033[1;33mForm\033[0m default constructor called" << std::endl;
	_signed = 0;
}

Form::Form( std::string name , int gradeToSign , int gradeToExec)
: _name( name ) , _lowestGrade_toSign( gradeToSign ) , _lowestGrade_toExec( gradeToExec )
{
	checkGrade_toSign();
	std::cout << "\033[1;33mForm\033[0m constructor called" << std::endl;
	_signed = 0;
}

Form::Form( const Form& other ) : _name(other._name),
_lowestGrade_toSign(other._lowestGrade_toSign), _lowestGrade_toExec(other._lowestGrade_toExec)
{
	std::cout << "\033[1;33mForm\033[0m copy constructor called" << std::endl;
	_signed = other._signed;
}

Form &Form::operator=( const Form& other )
{
	std::cout << "\033[1;33mForm\033[0m copy assignment called, "
			<< "but photocopier has no more ink, only signature was copied!"
			<< std::endl;
	_signed = other._signed;
	return ( *this );
}

Form::~Form()
{
	std::cout << "\033[1;33mForm\033[0m destructor called" << std::endl;
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

int			Form::getlowestGrade_toExec() const
{
	return ( _lowestGrade_toExec );
}

//****************************************************//
//                                                    //
//                    Functions                       //
//                                                    //
//****************************************************//

void	Form::checkGrade_toSign() const
{
	if ( _lowestGrade_toSign > _lowestGrade || _lowestGrade_toExec > _lowestGrade )
		throw Form::GradeTooLowException();
	else if ( _lowestGrade_toExec < _highestGrade || _lowestGrade_toSign < _highestGrade )
		throw Form::GradeTooHighException();
}

void Form::beSigned( const Bureaucrat &guy )
{
	if (_signed)
	{
		std::cout << "\033[1;33m" << _name << "\033[0m" << " is already signed."
				<< std::endl;
	}
	else if (guy.getGrade() > _lowestGrade_toSign)
		throw GradeTooLowToSign();
	else
	{
		_signed = true;
		std::cout << "\033[1;33m" << _name << "\033[0m" <<" was signed by " 
				<< "\033[1;34m" << guy.getName() << "\033[0m"
				<< std::endl;
	}

}

//****************************************************//
//                                                    //
//                     No-member                      //
//                                                    //
//****************************************************//

std::ostream &operator<<( std::ostream &out , const Form& value)
{
	out << value.getName() << " has to be signed by a bureaucrat whose grade is at least "
		<< value.getLowestGrade_toSign() << " and execute by a Bureaucrat whose grade is at least "
		<< value.getlowestGrade_toExec() << "." << std::endl;
	return ( out );
}