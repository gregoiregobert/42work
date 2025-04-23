#include "PMergeMe.hpp"

int	main( int ac, char **av )
{
	try{
		PMergeMe fusion(ac, av);
	}
	catch(std::exception &e){
			std::cerr << e.what() << std::endl;
		}
}