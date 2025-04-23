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
	try{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch(std::exception &e){
		(void)e;
	}
		try{
		B &b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "B" << std::endl;
	}
	catch(std::exception &e){
		(void)e;
	}	try{
		C &c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "C" << std::endl;
	}
	catch(std::exception &e){
		(void)e;
	}
}

int main()
{
	Base *p = genrate();
	identify(p);
	identify(&(*p));
	delete p;
}