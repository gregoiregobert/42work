#include "Animal.hpp"

class Dog : public Animal
{
	public:

		Dog( void );
		Dog( const Dog &src );
		virtual ~Dog( void );

		Dog &operator=( const Dog& other );

		virtual void makeSound() const;
};