#include "AAnimal.hpp"

class Cat : public AAnimal
{
	private:

		Brain *brain;

	public:

		Cat( void );
		Cat( const Cat &src );
		~Cat( void );

		Cat &operator=( const Cat& other );
		virtual AAnimal &operator=(const AAnimal& other);

		virtual void	makeSound() const;
		virtual Brain	*getBrain() const;
};