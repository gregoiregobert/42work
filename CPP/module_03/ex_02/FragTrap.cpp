#include "FragTrap.hpp"

//****************************************************//
//                                                    //
//               Constructor/Destructor               //
//                      Coplien                       //
//                                                    //
//****************************************************//

FragTrap::FragTrap( std::string name )
{
	std::cout << "FragTrap constructor called" << std::endl;

	_name = name;
	_HitPoint = 100;
	_EnergyPoint = 100;
	_AttackDamage = 30;
	_initialHit = _HitPoint;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor Called" << std::endl;
}

FragTrap::FragTrap( const FragTrap& other )
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	_name = other._name;
	_HitPoint = other._HitPoint;
	_EnergyPoint = other._EnergyPoint;
	_AttackDamage = other._AttackDamage;
	_initialHit = other._initialHit;
}

FragTrap &FragTrap::operator=( const FragTrap& other )
{
	std::cout << "FragTrap copy assignment alled" << std::endl;
	_name = other._name;
	_HitPoint = other._HitPoint;
	_EnergyPoint = other._EnergyPoint;
	_AttackDamage = other._AttackDamage;
	_initialHit = other._initialHit;
	return (*this);
}

//****************************************************//
//                                                    //
//                 Action Function                    //
//                                                    //
//****************************************************//

void	FragTrap::attack(const std::string& target)
{
	setEnergyPoint(-1);

	if (getHitPoint() <= 0)
	{
		std::cout << getName()
				<< " no longer live."
				<< std::endl;
	}

	if (getEnergyPoint() <= 0)
	{
		std::cout << getName()
			<< " is out of Energy."
			<< std::endl;
	}
	else
		std::cout << getName()
			<< " attacks " << target
			<< ", causing " << getAttackDamage()
			<< " point(s) of damage!"
			<< std::endl;
}

void	FragTrap::highFiveGuys()
{
	std::cout << getName()
			<< " ask for an \033[1;32mHigh Five\033[0m!"
			<< std::endl;
}
