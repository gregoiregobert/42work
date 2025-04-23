#include "ClapTrap.hpp"

int main()
{
	ClapTrap ClapTrap("John");

	ClapTrap.attack("Greg");
	ClapTrap.takeDamage(9);
	ClapTrap.beRepaired(5);
	ClapTrap.beRepaired(20);
	ClapTrap.takeDamage(5);
	ClapTrap.takeDamage(5);
	ClapTrap.beRepaired(20);
	ClapTrap.takeDamage(9);
}