#include "AAnimal.hpp"

class Dog : public AAnimal
{
	private:

		Brain	*brain;

	public:

		Dog( void );
		Dog( const Dog &src );
		~Dog( void );

		Dog &operator=( const Dog& other );
		virtual AAnimal &operator=(const AAnimal& other);

		virtual void	makeSound() const;
		Brain			*getBrain() const;
};