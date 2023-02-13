#include "Bureaucrat.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	try{
		Bureaucrat Phil("Phil", 120);
		Bureaucrat Dude("Dude", 10);
		Form	A555("A555", 10, 14);
		Form	B12("B12", 1, 1);
		

		A555.beSigned(Dude);
		A555.beSigned(Phil);
		Form	A556(A555);
		A556.beSigned(Phil);
		B12 = A556;
		Dude.signForm(B12);
	}
	catch(std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	try{
		Form	B46("B45", 0, 1);
	}
	catch(std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	try{
		Form	B45("B45", 0, 151);
	}
	catch(std::exception &e){
		std::cerr << e.what() << std::endl;
	}
}