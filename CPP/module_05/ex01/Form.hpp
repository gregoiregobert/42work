#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
    private:

        Form();

        std::string _name const;
        bool        _signed = 0;
        int         _lowestGrade = 150;
        int         _highestGrade = 1;
        int         _lowestGrade_toSign const;
        int         _highestGrade_toSign const;


    public:

        Form( std::string name , int lowestGrade , int highestGrade );
        Form( const Form& other );
        ~Form();

        Form& operator=( const Form& other );

        std::string getName() const;
        bool        getSigned() const;
        int         getLowestGrade_toSign() const;
        int         getHighestGrade_toSign() const;

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

        class GradeDifference : public std::exception
		{
			public:

			virtual const char* what() const throw()
			{
				return ("\033[1;31mGrades difference is negative\033[0m");
			}
		};
};
std::ostream    &operator<<( std::ostream &out, const Form &value );

#endif