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
	std::cout << "\033[1;34mBureaucrat\033[0m constructor called" << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat& other )
{
	std::cout << "\033[1;34mBureaucrat\033[0m copy constructor called" << std::endl;
	_name = other._name;
	_grade = other._grade;
}

Bureaucrat &Bureaucrat::operator=( const Bureaucrat& other )
{
	std::cout << "\033[1;34mBureaucrat\033[0m copy assignment called" << std::endl;
	_name = other._name;
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
		std::cerr << "Has to be a positif number" << std::endl;
	_grade -= level;
	if ( _grade < 1 )
		_grade = Bureaucrat::highestGrade;
}

void	Bureaucrat::decrementeGrade( int level )
{
	if ( level < 1 )
		std::cerr << "Has to be a positif number" << std::endl;
	if ( _grade > Bureaucrat::lowestGrade )	
		_grade = Bureaucrat::lowestGrade;
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