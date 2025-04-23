#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <cstdlib>

int main()
{
	std::vector<int> vec;
	int value;
	int search = 5;

	std::cout << "\033[1mWe look after \033[1;33m" << search << "\033[0m" << std::endl;
	srand(time(NULL));
	for (int i = 0; i < 5; i++){
		value = rand() % 10;
		vec.push_back(value);
	}

	std::vector<int>::iterator it = vec.begin();
	for (int i = 0; i < (int)vec.size(); i++)
		std::cout << *it++ << ' ';
	std::cout << std::endl;
	
	try{
		easyfind(vec, search);
	}
	catch(std::exception &e){
		std::cerr << e.what() << std::endl;
	}
}