#include "Animal.hpp"

class Dog : public Animal
{
	private:

		Brain	*brain;

	public:

		Dog( void );
		Dog( const Dog &src );
		~Dog( void );

		Dog &operator=( const Dog& other );
		virtual Animal &operator=(const Animal& other);

		virtual void	makeSound() const;
		Brain			*getBrain() const;
};