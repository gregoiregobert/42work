#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& Weapon) : _name(name), _weapon(Weapon)
{
	std::cout << "HumanA was born" << std::endl;
	return ;
}

HumanA::~HumanA(void)
{
	std::cout << "HumanA was dead" << std::endl;
	return ;
}

void	HumanA::attack(void)
{
	std::cout << this->_name << " attacks with their "
			<< this->_weapon.getType() << std::endl;
}