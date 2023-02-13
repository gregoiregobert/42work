#include "Base.hpp"

//****************************************************//
//                                                    //
//               Constructor/Destructor               //
//                                                    //
//****************************************************//

Base::Base()
{
	std::cout << "Base default constructor called" << std::endl;
}

Base::~Base()
{
	std::cout << "Base destructor called" << std::endl;
}

//****************************************************//
//                                                    //
//                    Functions                       //
//                                                    //
//****************************************************//

Base	*genrate( void )
{
	srand (time(NULL));

	if (std::rand() % 3 == 1)
	{	
		std::cout << "A" <<std::endl;
		return ( new A );
	}
	if (std::rand() % 3 == 2)
	{
		std::cout << "B" <<std::endl;
		return ( new B );
	}
	else
	{
		std::cout << "C" <<std::endl;
		return ( new C );
	}
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void	identify(Base &p)
{
	identify(&p);
}