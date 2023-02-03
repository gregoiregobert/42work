#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    protected:

        Form();

        std::string const 	_name;
        bool 				_signed;
    	static int	const	_lowestGrade = 150;
        static int	const	_highestGrade = 1;
        int const			_lowestGrade_toSign ;
        int const			_lowestGrade_toExec ;


    public:

        Form( std::string name , int gradeToSign , int gradeToExec );
        Form( const Form& other );
        virtual ~Form();

        Form& operator=( const Form& other );

        std::string getName() const;
        bool        getSigned() const;
        int         getLowestGrade_toSign() const;
        int         getlowestGrade_toExec() const;

        void    checkGrade_toSign() const;
		void	checkExec( const Bureaucrat& executor ) const;
        void    beSigned( const Bureaucrat &guy );
		virtual void	execute( const Bureaucrat& executor ) const = 0;

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

		class NotSigned : public std::exception
		{
			public:
			virtual const char* what() const throw()
			{
				return ("\033[1;31mForm is not signed, do you really work here?\033[0m");
			}
		};

		class GradeTooLowToSign : public std::exception
		{
			public:
			virtual const char* what() const throw()
			{
				return ("\033[1;31mGrade is to low to sign\033[0m");
			}
		};

		class GradeTooLowForExec : public std::exception
		{
			public:
			virtual const char* what() const throw()
			{
				return ("\033[1;31mThis bureaucrat can't execute this form with his/her grade\033[0m");
			}
		};
};
std::ostream    &operator<<( std::ostream &out, const Form &value );

#endif