#include "PresidentialPardonForm.hpp"
#include <fstream>

//****************************************************//
//                                                    //
//               Constructor/Destructor               //
//                      Coplien                       //
//                                                    //
//****************************************************//

PresidentialPardonForm::PresidentialPardonForm()
: Form ( "PresidentialPardonForm", 25, 5 ) , _target( "" )
{
	std::cout << "Default \033[1;37mPresidentialPardonForm\033[0m constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target )
: Form( "PresidentialPardonForm", 25, 5 ), _target( target )
{
	std::cout << "\033[1;37mPresidentialPardonForm\033[0m constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& other )
: Form("PresidentialPardonForm", 25, 5), _target(other._target)
{
	std::cout << "\033[1;37mPresidentialPardonForm\033[0m Copy constructor called" << std::endl;
	*this = other;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "\033[1;37mPresidentialPardonForm\033[0m destructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=( const PresidentialPardonForm& other )
{
	std::cout << "\033[1;37mPresidentialPardonForm\033[0m copy assignment called, but photocopier is broken" << std::endl;
	_target = other._target;
	_signed = other._signed;
	return ( *this );
}

//****************************************************//
//                                                    //
//                    Accessors                       //
//                                                    //
//****************************************************//

std::string	PresidentialPardonForm::getTarget() const
{
	return (_target);
}

//****************************************************//
//                                                    //
//                    Functions                       //
//                                                    //
//****************************************************//

void	PresidentialPardonForm::execute( const Bureaucrat& executor ) const
{
	checkExec( executor );
	
	std::cout << _target << " has been forgiven by Zaphod Beeblebrox." << std::endl;
}
