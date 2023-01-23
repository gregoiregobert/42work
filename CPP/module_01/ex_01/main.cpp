#include "Zombie.hpp"

int	main(void)
{
	Zombie		*Z;
	std::string name;

	std::cout << "Because we don't have time, we will call all your Zombies with the same name : ";
	std::getline(std::cin, name, '\n');
	Z = zombieHorde(12, name);
	delete [] Z;
}