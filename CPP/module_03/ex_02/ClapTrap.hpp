#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	protected:

		std::string _name;
		int	_HitPoint;
		int	_EnergyPoint;
		int	_AttackDamage;
		int	_initialHit;


	public:

		ClapTrap();
		ClapTrap( std::string name );
		ClapTrap( const ClapTrap& other );
		~ClapTrap();

		ClapTrap &operator=( const ClapTrap& other );

		void attack( const std::string& target );
		void takeDamage( unsigned int amount );
		void beRepaired( unsigned int amount );

		void		setHitPoint( int Point );
		int			getHitPoint() const;
		void		setEnergyPoint( int Point );
		int			getEnergyPoint() const;
		int			getAttackDamage() const;
		std::string getName() const;

};

#endif

