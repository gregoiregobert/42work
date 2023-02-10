#include <iostream>
#include <string>

int main()
{
	std::string test = "09f";
	int found;

	found = test.find(".");

	if (found!=std::string::npos)
		std::cout << "inegal" << std::endl;
}