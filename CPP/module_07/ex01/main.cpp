#include <iostream>
#include <string>
#include "iter.hpp"

template<class T>
void	on_screen(T &x)
{
	std::cout << x << std::endl;
}

template<class T>
void	plus_one(T &x)
{
	x++;
	std::cout << x << std::endl;
}

int	main()
{
	std::string str[5] = {"pouleeet", "poulette", "topla", "toplatoi", "kekeva"};
	iter(str, 5, &on_screen);

	std::cout << std::endl;

	int poulet[5] = {1, 1, 2, 5, 3};
	iter(poulet, 5, &plus_one);

	std::cout << std::endl;

	double nb[5] = {1.2, 1.3, 1.5, 5.9, 56.2};
	iter(nb, 5, &plus_one);
}