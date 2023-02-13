# ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include <stdexcept>
#include <limits.h>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:

		Bureaucrat();

		std::string	const _name;
		int			_grade;
		static const int	highestGrade = 1;
		static const int	lowestGrade = 150;

		void	CheckGrade() const;

	public:

		Bureaucrat( std::string name , int grade );
		Bureaucrat( const Bureaucrat &other );
		~Bureaucrat();

		Bureaucrat&	operator=( const Bureaucrat& other );

		std::string		getName() const;
		int				getGrade() const;

		void			incrementGrade( int level );
		void			decrementeGrade( int level );
		void			signForm( Form& form );
		void			executeForm( const Form& form );

		class GradeTooHighException : public std::exception
		{
			public:
			virtual const char* what() const throw()
			{
				return ("\033[1;31mThe grade you set is too high\033[0m");
			}
		};

		class GradeTooLowException : public std::exception
		{
			public:

			virtual const char* what() const throw()
			{
				return ("\033[1;31mThe grade you set is too low\033[0m");
			}
		};

};
std::ostream &operator<<(std::ostream &out, Bureaucrat const &value);

#endif