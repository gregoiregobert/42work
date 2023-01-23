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

	bool operator!=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;

	Fixed operator+(const Fixed &other);
	Fixed operator-(const Fixed &other);
	Fixed operator/(const Fixed &other);
	Fixed operator*(const Fixed &other);

	Fixed operator++();
	Fixed operator++(int);
	Fixed operator--();
	Fixed operator--(int);

	static Fixed const &max(Fixed const &a, Fixed const &b);
	static Fixed const  &min(Fixed const &a, Fixed const &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static Fixed &min(Fixed &a, Fixed &b);
	
	int getRawBits( void ) const;
	void setRawBits( int const raw );

	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, Fixed const &value);
Fixed const &max(Fixed const &a, Fixed const &b);
Fixed const  &min(Fixed const &a, Fixed const &b);
Fixed &max(Fixed &a, Fixed &b);
Fixed &min(Fixed &a, Fixed &b);

#endif