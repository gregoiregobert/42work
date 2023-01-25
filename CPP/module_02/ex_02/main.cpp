#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << "\n\033[1;31mOwn test\033[0m" << std::endl;
	Fixed c(5.5f);
	Fixed d(2);
	std::cout << "2 * 5.5 =	" << c * d
	<< "\n5.5 + 2 =	" << c + d
	<< "\n5.5 / 2 =	" << c / d 
	<< "\n5.5 - 2 =	" << c - d
	<< "\n5.5 < 2 =	" << (c < d)
	<< "\n5.5 > 2?	" << (c > d)
	<< "\n5.5 >= 5.5?	" << (c >= c)
	<< "\n5.5 != 2?	" << (c != d)
	<< "\n5.5 != 5.5?	" << (c != c)
	<< "\nmin ?" << min(c, d)
	<< std::endl;

	return 0;
}