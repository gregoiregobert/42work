#include "Warlock.hpp"

Warlock::Warlock(std::string name, std::string title): _name(name), _title(title)
{
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::Warlock(){}

Warlock::~Warlock()
{
	std::cout << _name << ": My job here is done!" << std::endl;
}

Warlock&	Warlock::operator=(Warlock const& other)
{
	_name = other._name;
	_title = other._title;

	return *this;
}

Warlock::Warlock(Warlock const& other)
{
	*this = other;
}

std::string const Warlock::getName() const
{
	return _name;
}

std::string const Warlock::getTitle() const
{
	return _title;
}

void	Warlock::setTitle(std::string const title)
{
	_title = title;
}

void	Warlock::introduce() const{
	std::cout << _name << ": I'm " <<  _name << ", " << _title << "!" << std::endl;
}