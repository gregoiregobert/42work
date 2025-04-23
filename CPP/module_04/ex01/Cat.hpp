#include "Animal.hpp"

class Cat : public Animal
{
	private:

		Brain	*brain;

	public:

		Cat( void );
		Cat( const Cat &src );
		~Cat( void );

		Cat &operator=( const Cat& other );
		virtual Animal &operator=(const Animal& other);

		virtual void	makeSound() const;
		virtual Brain	*getBrain() const;
};