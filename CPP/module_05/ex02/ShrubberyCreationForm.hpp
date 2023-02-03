#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H
#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
	private:

		ShrubberyCreationForm();

		std::string _target;

	public:

		ShrubberyCreationForm( std::string target );
		ShrubberyCreationForm( const ShrubberyCreationForm& other );
		~ShrubberyCreationForm();

		ShrubberyCreationForm &operator=( const ShrubberyCreationForm& other );


		std::string	getTarget() const;
		virtual void	execute( const Bureaucrat &executor ) const;
};

#endif