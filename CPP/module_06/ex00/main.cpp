#include <iostream>
#include "Analyst.hpp"

int main(int ac, char **av)
{
	try{
		if (ac != 2)
			throw Analyst::EnoughArg();
		
		Analyst one(av[1]);
		one.detect_type();
	}
	catch(std::exception &e){
		std::cerr << e.what() << std::endl;
	}
}