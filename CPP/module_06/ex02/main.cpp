#include "Base.hpp"

int main()
{
	Base *p = genrate();
	identify(p);
	identify(&(*p));
}