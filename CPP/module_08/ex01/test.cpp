#include <iostream>
#include <vector>
#include<algorithm>

int main()
{
	std::vector<int> foo {1, 2, 33, 4, -5};

	std::cout << *std::max_element(foo.begin(), foo.end()) << std::endl;
	std::cout << *std::min_element(foo.begin(), foo.end()) << std::endl;
}