#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
	Zombie	*Z = new Zombie(name);

	return (Z);
}

Zombie* zombieHorde( int N, std::string name )
{
	Zombie	*Z = new Zombie[N];
	

}

Zombie::Zombie(std::string name) : _name(name)
{
	return;
}

Zombie::~Zombie(void)
{
	std::cout << this->_name << " was headshot." << std::endl;
	return;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..."
			<< std::endl;
}
