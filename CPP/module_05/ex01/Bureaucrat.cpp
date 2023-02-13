#include "Bureaucrat.hpp"

//****************************************************//
//                                                    //
//               Constructor/Destructor               //
//                      Coplien                       //
//                                                    //
//****************************************************//

Bureaucrat::Bureaucrat() : _name("unknown") , _grade( Bureaucrat::lowestGrade )
{
	std::cout << "\033[1;34mBureaucrat\033[0m default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat( std::string name , int grade ) : _name(name) , _grade (grade)
{
	CheckGrade();
	std::cout << "\033[1;34mBureaucrat\033[0m constructor called" << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat& other ) : _name(other._name)
{
	std::cout << "\033[1;34mBureaucrat\033[0m copy constructor called" << std::endl;
	_grade = other._grade;
}

Bureaucrat &Bureaucrat::operator=( const Bureaucrat& other )
{
	std::cout << "\033[1;34mBureaucrat\033[0m copy assignment called" << std::endl;
	_grade = other._grade;
	return ( *this );
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "\033[1;34mBureaucrat\033[0m destructor called" << std::endl;
}

//****************************************************//
//                                                    //
//                    Accessors                       //
//                                                    //
//****************************************************//

std::string	Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

//****************************************************//
//                                                    //
//                    Functions                       //
//                                                    //
//****************************************************//

void	Bureaucrat::CheckGrade() const 
{
	if ( getGrade() > 150 )
		throw Bureaucrat::GradeTooLowException();
	if ( getGrade() < 1 )
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::incrementGrade( int level )
{
	if ( level < 1 )
		std::cerr << "\033[1;31mHas to be a positif number\033[0m" << std::endl;

	_grade -= level;
	if ( _grade < 1 )
	{
		std::cout << "\033[1;31mAdjust to highest grade\033[0m" << std::endl;
		_grade = Bureaucrat::highestGrade;
	}
}

void	Bureaucrat::decrementeGrade( int level )
{
	if ( level < 1 )
	{
		std::cerr << "\033[1;31mHas to be a positif number\033[0m" << std::endl;
		return ;
	}
	_grade += level;
	if ( _grade > Bureaucrat::lowestGrade )	
	{
		std::cout << "\033[1;31mAdjust to lowest grade\033[0m" << std::endl;
		_grade = Bureaucrat::lowestGrade;
	}
}

void	Bureaucrat::signForm( Form& form )
{
	form.beSigned(*this);
}

//****************************************************//
//                                                    //
//                     No-member                      //
//                                                    //
//****************************************************//


std::ostream &operator<<(std::ostream &out, Bureaucrat const &value)
{
    out << value.getName() << ", bureaucrat grade "
		<< value.getGrade() << ".";
    return (out);
}