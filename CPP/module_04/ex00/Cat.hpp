#include "Animal.hpp"

class Cat : public Animal
{
	public:

		Cat( void );
		Cat( const Cat &src );
		~Cat( void );

		Cat &operator=( const Cat& other );

		virtual void makeSound() const;
};