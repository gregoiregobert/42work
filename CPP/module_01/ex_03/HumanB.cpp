#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
	std::cout << "HumanB was born" << std::endl;
	return ;
}

HumanB::~HumanB(void)
{
	std::cout << "HumanB was dead" << std::endl;
	return ;
}

void	HumanB::setWeapon(Weapon weapon)
{
	this->_weapon = &weapon;
}

void	HumanB::attack(void)
{
	std::cout << this->_name << " attacks with their "
			<< this->_weapon->getType() << std::endl;
}