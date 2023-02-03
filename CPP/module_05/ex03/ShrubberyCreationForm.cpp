#include "ShrubberyCreationForm.hpp"
#include <fstream>

//****************************************************//
//                                                    //
//               Constructor/Destructor               //
//                      Coplien                       //
//                                                    //
//****************************************************//

ShrubberyCreationForm::ShrubberyCreationForm()
: Form ( "ShrubberyCreationForm", 145, 137 ) , _target( "" )
{
	std::cout << "Default \033[1;32mShrubberyCreationForm\033[0m constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target )
: Form( "ShrubberyCreationForm", 145, 137 ), _target( target )
{
	std::cout << "\033[1;32mShrubberyCreationForm\033[0m constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& other )
: Form("ShrubberyCreationForm", 145, 137), _target(other._target)
{
	std::cout << "\033[1;32mShrubberyCreationForm\033[0m Copy constructor called" << std::endl;
	*this = other;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "\033[1;32mShrubberyCreationForm\033[0m destructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=( const ShrubberyCreationForm& other )
{
	std::cout << "\033[1;32mShrubberyCreationForm\033[0m copy assignment called, but photocopier is broken" << std::endl;
	_target = other._target;
	_signed = other._signed;
	return ( *this );
}

//****************************************************//
//                                                    //
//                    Accessors                       //
//                                                    //
//****************************************************//

std::string	ShrubberyCreationForm::getTarget() const
{
	return (_target);
}

//****************************************************//
//                                                    //
//                    Functions                       //
//                                                    //
//****************************************************//

void	ShrubberyCreationForm::execute( const Bureaucrat& executor ) const
{
	checkExec( executor );

	std::string		newFile = _target + "_shrubbery";
	std::ofstream	myfile;

	myfile.open(newFile.c_str(), std::ios::out);
	myfile << "      ,.," << std::endl;
	myfile << "      MMMM_    ,..," << std::endl;
	myfile << "        \"_ \"__\"MMMMM          ,...,," << std::endl;
	myfile << " ,..., __.\" --\"    ,.,     _-\"MMMMMMM" << std::endl;
	myfile << "MMMMMM\"___ \"_._   MMM\"_.\"\" _ \"\"\"\"\"\"" << std::endl;
	myfile << " \"\"\"\"\"    \"\" , \\_.   \"_. .\"" << std::endl;
	myfile << "        ,., _\"__ \\__./ .\"" << std::endl;
	myfile << "       MMMMM_\"  \"_    ./" << std::endl;
	myfile << "        ''''      (    )" << std::endl;
	myfile << " ._______________.-'____\"---._." << std::endl;
	myfile << "  \\                          /" << std::endl;
	myfile << "   \\________________________/" << std::endl;
	myfile << "   (_)                    (_)" << std::endl;
	myfile.close();
	std::cout << "A tree has grown" << std::endl;
}
