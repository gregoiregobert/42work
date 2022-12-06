#include "Zombie.hpp"

int	main()
{
	std::string myname;
	Zombie	*dead;

	std::cout << "zombie's name on heap:" << std::endl;
	std::getline(std::cin, myname, '\n');
	dead = newZombie(myname);
	std::cout << "zombie's name on stack:" << std::endl;
	std::getline(std::cin, myname, '\n');
	randomChump(myname);
	dead->announce();
	delete dead;
}