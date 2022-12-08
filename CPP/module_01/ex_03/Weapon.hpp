#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
	public:
		Weapon(void);
		~Weapon(void);

		Weapon(std::string weapon);
		void		setType(std::string str);
		std::string	getType(void);
	private:

		std::string	_type;
};

#endif