#include "Span.hpp"

int main()
{
	try{
		Span sp = Span(10000);
		// sp.addNumber(6);
		// sp.addNumber(3);
		// sp.addNumber(17);
		// sp.addNumber(9);

		sp.addRandom();

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	}
	catch(std::exception &e){
		std::cerr << e.what() << std::endl;
	}

	try{
		Span 				sp = Span(5);
		std::vector<int>	foo;

		foo.push_back(4);
		foo.push_back(5);
		foo.push_back(56);
		foo.push_back(87);
		foo.push_back(930);
		sp.addNumber( foo.begin(), foo.end() );
		std::cout << sp << std::endl;

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(std::exception &e){
		std::cerr << e.what() << std::endl;
	}

	return 0;
}