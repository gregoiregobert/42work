#include "Bureaucrat.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

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
		Bureaucrat Dude("Dude", 150);
		ShrubberyCreationForm Tree("backyard");
		PresidentialPardonForm Pardon("Arthur");
		RobotomyRequestForm	Robot("Bender");
		// Form	B45("B45", 0, 151);

		std::cout << "\n//****************************************************//\n"
			<< "//                                                    //\n"
			<< "//                Shrubbery Creation                  //\n"
			<< "//                                                    //\n"
			<< "//****************************************************//\n"
			<< std::endl;

		Tree.beSigned(Phil);
		// Tree.execute(Dude);
		Tree.execute(Phil);
		
		std::cout << "\n//****************************************************//\n"
			<< "//                                                    //\n"
			<< "//               Presidential pardon                  //\n"
			<< "//                                                    //\n"
			<< "//****************************************************//\n"
			<< std::endl;

		Phil.signForm(Pardon);
		Pardon.execute(Phil);

		std::cout << "\n//****************************************************//\n"
			<< "//                                                    //\n"
			<< "//               Robotomy Request                     //\n"
			<< "//                                                    //\n"
			<< "//****************************************************//\n"
			<< std::endl;

		Phil.signForm(Robot);
		Phil.executeForm(Robot);

		std::cout << "\n//****************************************************//\n"
			<< "//                                                    //\n"
			<< "//                   Operator <<                      //\n"
			<< "//                                                    //\n"
			<< "//****************************************************//\n"
			<< std::endl;
		std::cout << Robot;
		std::cout << Pardon;
		std::cout << Tree;

		std::cout << "\n//****************************************************//\n"
			<< "//                                                    //\n"
			<< "//                   Destructor                       //\n"
			<< "//                                                    //\n"
			<< "//****************************************************//\n"
			<< std::endl;
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
		RobotomyRequestForm	Robot("Bender");
		Bureaucrat Dude("Dude", 150);
		// Bureaucrat Michel("Michel", 151);
		// Bureaucrat Louis("Louis", -1);
		// Form	A45("A45", 154, 22);

		// Robot.execute(Dude);
		Dude.signForm(Robot);
	}
	catch(std::exception &e){
		std::cerr << e.what() << std::endl;
	}
}