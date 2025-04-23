#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H
#include "Form.hpp"

class RobotomyRequestForm : public Form
{
	private:

		RobotomyRequestForm();

		std::string	_target;

	public:

		RobotomyRequestForm( std::string target );
		RobotomyRequestForm( const RobotomyRequestForm& other );
		~RobotomyRequestForm();

		RobotomyRequestForm& operator=( const RobotomyRequestForm& other );

		std::string	getTarget() const;
		virtual void	execute( const Bureaucrat &executor ) const;
};

#endif