#include "Zombie.hpp"

int	main()
{
	std::string myname;
	Zombie	*x;

	std::cin >> myname;
	x = newZombie(myname);
	randomChump(myname);
	delete x;
}