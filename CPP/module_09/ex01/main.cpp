#include "RPN.hpp"

int	main( int ac, char **av )
{
	try{
		RPN polish(ac, av);
	}
	catch(std::exception &e){
			std::cerr << e.what() << std::endl;
		}
}