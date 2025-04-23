#include "Bureaucrat.hpp"

int	main()
{
	try{
		Bureaucrat Phil("Phil", 150);
		Phil.decrementeGrade( 1 );
		std::cout << Phil << std::endl;
		Phil.incrementGrade ( 180 );
		std::cout << Phil << std::endl;
		Phil.decrementeGrade( 10 );
		std::cout << Phil << std::endl;
		Phil.incrementGrade ( 8 );
		std::cout << Phil << std::endl;
	}
	catch(std::exception &e){
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try{
		Bureaucrat Paul("Paul", 0);
	}
	catch(std::exception &e){
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try{
		Bureaucrat Paul("Paul", 151);
	}
	catch(std::exception &e){
		std::cerr << e.what() << std::endl;
	}
}