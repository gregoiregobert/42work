#include "FragTrap.hpp"

int main()
{
	FragTrap Paul("Paul");
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
	Paul.highFiveGuys();
	Paul.beRepaired(15);
	Paul.takeDamage(75);
	Paul.beRepaired(15);
}