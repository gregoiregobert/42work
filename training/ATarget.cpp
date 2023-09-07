#include "ATarget.hpp"

ATarget::ATarget(std::string type): _type(type)
{}

ATarget::~ATarget(){}

ATarget &ATarget::operator=(ATarget const & other)
{
	_type = other._type;
	return *this;
}

ATarget::ATarget(ATarget const & other)
{
	*this = other;
}

std::string const ATarget::getType() const
{
	return _type;
}

void	ATarget::getHitBySpell(ASpell const &spell) const
{
	std::cout << _type << " has been " << spell.getEffect() << std::endl;
}