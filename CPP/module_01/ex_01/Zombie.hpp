#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class	Zombie
{
	public:

	// constructor //

		Zombie(void);
		~Zombie(void);

		Zombie(std::string name);

	// methode //

		void 	announce( void );
		void	setName(std::string name);

	private:
	
		std::string _name;
};

Zombie* zombieHorde( int N, std::string name );

#endif