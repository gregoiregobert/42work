#include "Fixed.hpp"

//****************************************************//
//                                                    //
//               Constructor/Destructor               //
//                                                    //
//****************************************************//

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	_value = other.getRawBits();
}

Fixed &Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_value = other.getRawBits();
	return *this;
}

Fixed::Fixed(const int nb)
{
	std::cout << "Int constructor called" << std::endl;
	_value = nb << Fixed::fractionnalBits;
}

Fixed::Fixed(const float nb)
{
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(nb * (1 << Fixed::fractionnalBits));
}

//****************************************************//
//                                                    //
//                     Functions                      //
//                                                    //
//****************************************************//

int Fixed::getRawBits() const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void	Fixed::setRawBits(int const raw)
{
	_value = raw;
}

int	Fixed::toInt() const
{
	return (_value >> Fixed::fractionnalBits);
}

float	Fixed::toFloat() const
{
	return ((float)_value / (float)(1 << Fixed::fractionnalBits));
}

//****************************************************//
//                                                    //
//                     Operators                      //
//                                                    //
//****************************************************//

std::ostream &operator<<(std::ostream &out, Fixed const &value)
{
    out << value.toFloat();
    return (out);
}

