#include "Span.hpp"

int main()
{

/*__________________________________*/
/*|     Short and Longuest test    |*/
/*|________________________________|*/

	try{
		std::cout << "___________________________" << std::endl
				<< "\033[1m| Short and Longuest test |\033[0m" << std::endl
				<< "|_________________________|" << std::endl;
		Span sp = Span(10000);

		sp.addRandom();

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	}
	catch(std::exception &e){
		std::cerr << e.what() << std::endl;
	}

/*__________________________________*/
/*|     range of iterators test    |*/
/*|________________________________|*/

	try{
		Span 				sp = Span(5);
		std::vector<int>	foo;

		std::cout << std::endl << "___________________________" << std::endl
				<< "\033[1m| range of iterators test |\033[0m" << std::endl
				<< "|_________________________|" << std::endl;
		foo.push_back(4);
		foo.push_back(5);
		foo.push_back(56);
		foo.push_back(87);
		foo.push_back(930);
		// fill one more test \\
		// foo.push_back(90);
		sp.addNumber( foo.begin(), foo.end() );
		std::cout << sp << std::endl;

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(std::exception &e){
		std::cerr << e.what() << std::endl;
	}

/*__________________________________*/
/*|         Errors test            |*/
/*|________________________________|*/

	try{
		std::cout << "______________" << std::endl
				<< "\033[1m| Errors test |\033[0m" << std::endl
				<< "|_____________|" << std::endl;
		Span	sp = Span(1);
		sp.addNumber(666);
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch(std::exception &e){
		std::cerr << e.what() << std::endl;
	}

/*__________________________________*/
/*|         Errors test            |*/
/*|________________________________|*/

	try{
		std::cout << "______________" << std::endl
				<< "\033[1m| Errors test |\033[0m" << std::endl
				<< "|_____________|" << std::endl;
		Span	sp = Span(1);
		sp.addNumber(666);
		sp.addNumber(999);
	}
	catch(std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	return 0;
}