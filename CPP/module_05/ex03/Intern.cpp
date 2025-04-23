#include "Intern.hpp"

//****************************************************//
//                                                    //
//               Constructor/Destructor               //
//                      Coplien                       //
//                                                    //
//****************************************************//

Intern::Intern() 
{
	std::cout << "\033[1;34mIntern\033[0m default constructor called" << std::endl;
}

Intern::Intern( const Intern& other )
{
	std::cout << "\033[1;34mIntern\033[0m copy constructor called" << std::endl;
	*this = other;
}

Intern &Intern::operator=( const Intern& other )
{
	(void)other;
	std::cout << "\033[1;34mIntern\033[0m copy assignment called" << std::endl;
	return ( *this );
}

Intern::~Intern()
{
	std::cout << "\033[1;34mIntern\033[0m destructor called" << std::endl;
}

//****************************************************//
//                                                    //
//                    Functions                       //
//                                                    //
//****************************************************//

Form *Intern::Shrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

Form *Intern::Presidential(std::string target)
{
	return (new PresidentialPardonForm(target));
}

Form *Intern::Robotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

Form	*Intern::makeForm( std::string formName, std::string formTarget )
{
	Form *(Intern::*fct[])(std::string) = {&Intern::Shrubbery, &Intern::Presidential, &Intern::Robotomy};
	std::string type[] = {"shrubbery creation", "presidential pardon", "robotomy request"};
	
	for (int i = 0; i < 3; i++)
		if (type[i] == formName)
			return ( (this->*fct[i])(formTarget) );
	std::cout << "The intern can't find \033[1;31m" << formName << "\033[0m form!" << std::endl;
	return (0);
}