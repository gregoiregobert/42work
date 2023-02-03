#ifndef INTERN_H
# define INTERN_H

#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
	private:

		Form 	*Shrubbery( std::string target );
		Form 	*Robotomy( std::string target );
		Form 	*Presidential( std::string target );

	public:

		Intern();
		Intern( const Intern& other );
		virtual ~Intern();

		Intern &operator=( const Intern& other );

		Form	*makeForm( std::string formName, std::string formTarget );
};

#endif
