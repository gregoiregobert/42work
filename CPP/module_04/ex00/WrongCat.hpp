#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:

		WrongCat( void );
		WrongCat( const WrongCat &src );
		virtual ~WrongCat( void );

		WrongCat &operator=( const WrongCat& other );
};