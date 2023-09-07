#pragma once
#include <iostream>
#include <map>
#include "ASpell.hpp"

class Warlock
{
	private:

		std::map <std::string, ASpell*> _spellBook;
		std::string _name;
		std::string _title;
		Warlock& operator=(Warlock const &ohter);
		Warlock(Warlock const & other);
		Warlock();

	public:

		Warlock(std::string name, std::string title);
		~Warlock();

		std::string const	getName() const;
		std::string const	getTitle() const;

		void	setTitle(std::string const &title);
		void	introduce()	const;

		void	learnSpell(ASpell *spell);
		void	forgetSpell(std::string spell);
		void	launchSpell(std::string, ATarget& target);
};