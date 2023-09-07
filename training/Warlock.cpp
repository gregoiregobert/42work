#include "Warlock.hpp"

Warlock::Warlock(std::string name, std::string title): _name(name), _title(title)
{
	std::cout <<  _name << ": This looks like another boring day." << std::endl;
}

Warlock::Warlock(){}

Warlock::~Warlock()
{
	std::cout << _name << ": My job here is done!" << std::endl;
}

Warlock &Warlock::operator=(Warlock const & other)
{
	_name = other._name;
	_title = other._title;
	return *this;
}

Warlock::Warlock(Warlock const & other)
{
	*this = other;
}

std::string	const Warlock::getName() const
{
	return _name;
}

std::string	const Warlock::getTitle() const
{
	return _title;
}

void	Warlock::setTitle(std::string const &str)
{
	_title = str;
}

void	Warlock::introduce() const
{
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

void	Warlock::learnSpell(ASpell *spell)
{
	if (spell)
		_spellBook[spell->getName()] = spell;
}

void	Warlock::forgetSpell(std::string spellName)
{
	if ( _spellBook.find(spellName) != _spellBook.end() )
		_spellBook.erase(_spellBook.find(spellName));
}

void	Warlock::launchSpell(std::string spellName, ATarget &target)
{
	if ( _spellBook.find(spellName) != _spellBook.end() )
		_spellBook[spellName]->launch(target);
}