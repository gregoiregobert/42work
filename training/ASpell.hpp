#pragma once
#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell{

	protected:

		std::string _name;
		std::string _effect;

	public:

		ASpell(std::string name, std::string effect);
		virtual ~ASpell();
		ASpell(ASpell const &other);
		ASpell &operator=(ASpell const& other);

		std::string getName() const;
		std::string getEffect() const;

		virtual ASpell *clone() const = 0;
		void	launch(ATarget const &target) const;
};