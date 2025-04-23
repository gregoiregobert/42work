#include "ScavTrap.hpp"

int main()
{
	ScavTrap Paul("Paul");
	ClapTrap Philipp("Philipp");
	
	Philipp.attack("Greg");
	Philipp.beRepaired(5);
	Philipp.takeDamage(8);
	Philipp.beRepaired(5);
	Philipp.takeDamage(8);
	Philipp.beRepaired(5);

	Paul.attack("Greg");
	Paul.beRepaired(15);
	Paul.takeDamage(40);
	Paul.guardGate();
	Paul.beRepaired(15);
	Paul.takeDamage(75);
	Paul.beRepaired(15);
}