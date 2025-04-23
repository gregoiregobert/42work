#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int	main()
{
	try{
		std::cout << "//****************************************************//\n"
			<< "//                                                    //\n"
			<< "//                   Constructor                      //\n"
			<< "//                                                    //\n"
			<< "//****************************************************//\n"
			<< std::endl;
		Bureaucrat Phil("Phil", 1);
		Intern	Matteo;
		Form *formulaire;
		Form *formulaire1;
		Form *formulaire2;

		formulaire = Matteo.makeForm("shrubbery creation", "jardin");
		formulaire1 = Matteo.makeForm("presidential pardon", "jardin");
		formulaire2 = Matteo.makeForm("robotomy request", "jardin");

		std::cout << "\n//****************************************************//\n"
			<< "//                                                    //\n"
			<< "//                 Sign & execute                     //\n"
			<< "//                                                    //\n"
			<< "//****************************************************//\n"
			<< std::endl;

		Phil.signForm(*formulaire);
		Phil.executeForm(*formulaire);

		std::cout << "\n//****************************************************//\n"
			<< "//                                                    //\n"
			<< "//                   Destructor                       //\n"
			<< "//                                                    //\n"
			<< "//****************************************************//\n"
			<< std::endl;
		delete formulaire;
		delete formulaire1;
		delete formulaire2;
	}
	catch(std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	try{
		std::cout << "\n//****************************************************//\n"
			<< "//                                                    //\n"
			<< "//                     Error(s)                       //\n"
			<< "//                                                    //\n"
			<< "//****************************************************//\n"
			<< std::endl;

		Intern	Jade;
		Form *formulaire2;
		
		formulaire2 = Jade.makeForm("nimp", "Pouleeet");
	}
	catch(std::exception &e){
		std::cerr << e.what() << std::endl;
	}
}