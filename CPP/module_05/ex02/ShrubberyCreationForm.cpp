#include "ShrubberyCreationForm.hpp"

//****************************************************//
//                                                    //
//               Constructor/Destructor               //
//                      Coplien                       //
//                                                    //
//****************************************************//

ShrubberyCreationForm::ShrubberyCreationForm()
: From ("ShrubberyCreationForm", 145, 137) , _target("")
{
	std::cout << "Default ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationFrom( std::string target )
: Form("ShrubberyCreationForm", 145, 137), _target(taget)
{
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& other )
: Form("ShrubberyCreationForm", 145, 137), _target(other.target)
{

}