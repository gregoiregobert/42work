#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	int		i = -1;
	Zombie	*Z = new Zombie[N];

	while (++i < N)
	{
		Z[i].setName(name);
		Z[i].announce();
	}
	return (Z);
}
