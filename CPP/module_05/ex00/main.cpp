#include "Bureaucrat.hpp"

int	main()
{
	try{
		Bureaucrat Phil("Phil", 150);
		Phil.decrementeGrade( 1 );
		Phil.incrementGrade ( 120 );
		std::cout << Phil << std::endl;
	}
	catch(std::exception &e){
		std::cerr << e.what() << std::endl;
	}

	try{
		Bureaucrat Paul("Paul", 0);
	}
	catch{
		std::cerr << e.what() << std::endl;
	}
}