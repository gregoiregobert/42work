#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:

	int _value;
	static const int fractionnalBits = 8;

public:

	Fixed();
	Fixed(const int nb);
	Fixed(const float nb);
	Fixed(const Fixed &other);
	~Fixed();

	Fixed &operator=(const Fixed &other);
	
	int getRawBits( void ) const;
	void setRawBits( int const raw );

	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, Fixed const &value);

#endif