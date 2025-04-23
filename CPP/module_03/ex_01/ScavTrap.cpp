#include "ScavTrap.hpp"

//****************************************************//
//                                                    //
//               Constructor/Destructor               //
//                      Coplien                       //
//                                                    //
//****************************************************//

ScavTrap::ScavTrap( std::string name )
{
	std::cout << "ScavTrap constructor called" << std::endl;

	_name = name;
	_HitPoint = 100;
	_EnergyPoint = 50;
	_AttackDamage = 20;
	_initialHit = _HitPoint;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor Called" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap& other )
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	_name = other._name;
	_HitPoint = other._HitPoint;
	_EnergyPoint = other._EnergyPoint;
	_AttackDamage = other._AttackDamage;
	_initialHit = other._initialHit;
}

ScavTrap &ScavTrap::operator=( const ScavTrap& other )
{
	std::cout << "ScavTrap copy assignment alled" << std::endl;
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

void	ScavTrap::attack(const std::string& target)
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

void	ScavTrap::guardGate()
{
	std::cout << getName()
			<< " enter in \033[1;34mGate keeper\033[0m mode"
			<< std::endl;
}
