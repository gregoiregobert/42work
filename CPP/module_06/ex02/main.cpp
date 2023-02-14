#include <cstdlib>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*genrate( void )
{
	srand (time(NULL));

	if (std::rand() % 3 == 1)
		return ( new A );
	if (std::rand() % 3 == 2)
		return ( new B );
	else
		return ( new C );
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

int main()
{
	Base *p = genrate();
	identify(p);
	identify(&(*p));
	delete p;
}