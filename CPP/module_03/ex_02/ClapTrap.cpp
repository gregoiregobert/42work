#include "ClapTrap.hpp"

//****************************************************//
//                                                    //
//               Constructor/Destructor               //
//                      Coplien                       //
//                                                    //
//****************************************************//

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap default constructor called" << std::endl;
	_HitPoint = 10;
	_EnergyPoint = 10;
	_AttackDamage = 0;
	_initialHit = _HitPoint;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap::ClapTrap( std::string name) : _name(name)
{
	std::cout << "ClapTrap Constructor called" << std::endl;
	_HitPoint = 10;
	_EnergyPoint = 10;
	_AttackDamage = 0;
	_initialHit = _HitPoint;
}

ClapTrap::ClapTrap( const ClapTrap& other )
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	_name = other._name;
	_HitPoint = other._HitPoint;
	_EnergyPoint = other._EnergyPoint;
	_AttackDamage = other._AttackDamage;
}

ClapTrap &ClapTrap::operator=( const ClapTrap& other )
{
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
	_name = other._name;
	_HitPoint = other._HitPoint;
	_EnergyPoint = other._EnergyPoint;
	_AttackDamage = other._AttackDamage;
	return (*this);
}

//****************************************************//
//                                                    //
//                     Accessors                      //
//                                                    //
//****************************************************//

void	ClapTrap::setHitPoint(int Point)
{
	_HitPoint += Point;
	if (_HitPoint < 0)
		_HitPoint = 0;
	if ( _HitPoint > _initialHit )
		_HitPoint = _initialHit;
}

int	ClapTrap::getHitPoint() const
{
	return (_HitPoint);
}

void	ClapTrap::setEnergyPoint(int Point)
{
	_EnergyPoint += Point;
	if (_EnergyPoint < 0)
		_EnergyPoint = 0;
}

int	ClapTrap::getEnergyPoint() const
{
	return (_EnergyPoint);
}

int	ClapTrap::getAttackDamage() const
{
	return (_AttackDamage);
}

std::string ClapTrap::getName() const
{
	return (_name);
}

//****************************************************//
//                                                    //
//                 Action Function                    //
//                                                    //
//****************************************************//

void ClapTrap::attack(const std::string& target)
{
	setEnergyPoint(-1);

	if (getHitPoint() <= 0)
	{
		std::cout << getName()
				<< " no longer live."
				<< std::endl;
		return ;
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

void ClapTrap::takeDamage( unsigned int amount )
{
	if (amount > 2147483647)
	{
		std::cout << "Value is out of range [0 ~ 2147483647]" << std::endl;
		return ;
	}

	if (getHitPoint() <= 0)
	{
		std::cout << getName()
				<< " is already broken."
				<<std::endl;
		return ;
	}

	setHitPoint((int)-amount);

	std::cout << getName()
			<< " take\033[31m " << amount
			<< "\033[0m point(s) of damage!	"
			<< "\033[31m" << getHitPoint() << "\033[1;37mHP\033[0m "
			<< "\033[33m" << getEnergyPoint() << "\033[1;37mMP\033[0m"
			<<std::endl;

	if (getHitPoint() <= 0)
		std::cout << getName()
				<< " is totally broken.\n\033[1;31mGAME OVER...\033[0m"
				<<std::endl;
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	setEnergyPoint(-1);

	if (getHitPoint() <= 0)
	{
		std::cout << getName()
				<< " no longer live."
				<< std::endl;
		return ;
	}

	if (getEnergyPoint() <= 0)
	{
		std::cout << getName()
			<< " is out of Energy."
			<< std::endl;
	}

	setHitPoint(amount);

	std::cout << getName()
			<< " gain \033[31m" << amount
			<< " \033[0mheal point(s)		"
			<< "\033[31m" << getHitPoint() << "\033[1;37mHP\033[0m "
			<< "\033[33m" << getEnergyPoint() << "\033[1;37mMP\033[0m"
			<< std::endl;
}


