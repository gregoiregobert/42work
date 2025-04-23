#include <string>
#include <iostream>

int	main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *strPTR = &str;
	std::string &strREF = str;

	std::cout << "adresse de str :	" << &str << std::endl;
	std::cout << "strPTR :		" << strPTR << std::endl;
	std::cout << "pstrREF :		" << &strREF << std::endl;
	
	std::cout << "\nstr :		" << str << std::endl;
	std::cout << "*strPTR :	" << *strPTR << std::endl;
	std::cout << "strREF :	" << strREF << std::endl;
}