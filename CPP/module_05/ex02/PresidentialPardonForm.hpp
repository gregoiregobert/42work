#ifndef PRESIDENTIALPARDONFOR_H
# define PRESIDENTIALPARDONFOR_H
#include "Form.hpp"

class PresidentialPardonForm : public Form
{
	private:

		PresidentialPardonForm();

		std::string	_target;

	public:

		PresidentialPardonForm( std::string target );
		PresidentialPardonForm( const PresidentialPardonForm& other );
		~PresidentialPardonForm();

		PresidentialPardonForm& operator=( const PresidentialPardonForm& other );

		std::string	getTarget() const;
		virtual void	execute( const Bureaucrat &executor ) const;
};

#endif