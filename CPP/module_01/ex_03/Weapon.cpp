#include "Weapon.hpp"

Weapon::Weapon(std::string weapon) : _type(weapon)
{
	std::cout << "Weapon was created." << std::endl;
	return ;
}

Weapon::Weapon(void)
{
	std::cout << "Weapon was created." << std::endl;
	return ;
}

Weapon::~Weapon(void)
{
	std::cout << "Weapon was detroyed." << std::endl;
	return ;
}

void	Weapon::setType(std::string str)
{
	this->_type = str;
}

std::string	Weapon::getType(void)
{
	return (this->_type);
}
