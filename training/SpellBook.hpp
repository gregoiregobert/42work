#pragma once
#include <iostream>
#include <map>
#include "ASpell.hpp"

class SpellBook
{
	private:

		SpellBook(SpellBook const & other);
		SpellBook& operator=(SpellBook const &other);
		std::map <std::string, ASpell*> _spellBook;

	public:

		void	learnSpell(ASpell* spell);
		void	forgetSpell(std::string const &spell);
		ASpell*	createSpell(std::string const &spell);

};