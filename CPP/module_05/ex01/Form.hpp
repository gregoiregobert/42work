#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:

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
        ~Form();

        Form& operator=( const Form& other );

        std::string getName() const;
        bool        getSigned() const;
        int         getLowestGrade_toSign() const;
        int         getlowestGrade_toExec() const;

        void    checkGrade_toSign() const;
        void    beSigned( const Bureaucrat &guy );

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

        class GradeTooLowToSign : public std::exception
		{
			public:

			virtual const char* what() const throw()
			{
				return ("\033[1;31mGrade too low to sign\033[0m");
			}
		};
};
std::ostream    &operator<<( std::ostream &out, const Form &value );

#endif