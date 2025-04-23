#include "RobotomyRequestForm.hpp"
#include <fstream>
#include <cstdlib>

//****************************************************//
//                                                    //
//               Constructor/Destructor               //
//                      Coplien                       //
//                                                    //
//****************************************************//

RobotomyRequestForm::RobotomyRequestForm()
: Form ( "RobotomyRequestForm", 72, 45 ) , _target( "" )
{
	std::cout << "Default \033[1;30mRobotomyRequestForm\033[0m constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( std::string target )
: Form( "RobotomyRequestForm", 72, 45 ), _target( target )
{
	std::cout << "\033[1;30mRobotomyRequestForm\033[0m constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& other )
: Form("RobotomyRequestForm", 72, 45), _target(other._target)
{
	std::cout << "\033[1;30mRobotomyRequestForm\033[0m Copy constructor called" << std::endl;
	*this = other;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "\033[1;30mRobotomyRequestForm\033[0m destructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=( const RobotomyRequestForm& other )
{
	std::cout << "\033[1;30mRobotomyRequestForm\033[0m copy assignment called, but photocopier is broken" << std::endl;
	_target = other._target;
	_signed = other._signed;
	return ( *this );
}

//****************************************************//
//                                                    //
//                    Accessors                       //
//                                                    //
//****************************************************//

std::string	RobotomyRequestForm::getTarget() const
{
	return (_target);
}

//****************************************************//
//                                                    //
//                    Functions                       //
//                                                    //
//****************************************************//

void	RobotomyRequestForm::execute( const Bureaucrat& executor ) const
{
	checkExec( executor );
	
	std::cout << "* SOME DRILL NOISE *" << std::endl;
	srand (time(NULL));

	if (std::rand() % 2)
		std::cout << _target << " has been succesfully robotomized!" << std::endl;
	else
		std::cout << "Damn! We loose a screw!! " << std::endl;
}
