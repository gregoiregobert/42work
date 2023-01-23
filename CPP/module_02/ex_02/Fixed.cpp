#include "Fixed.hpp"

//****************************************************//
//                                                    //
//               Constructor/Destructor               //
//                                                    //
//****************************************************//

Fixed::Fixed()
{
	// std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed& other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	_value = other.getRawBits();
	return *this;
}

Fixed::Fixed(const Fixed& other)
{
	// std::cout << "Copy constructor called" << std::endl;
	_value = other.getRawBits();
}

Fixed::Fixed(const int nb)
{
	// std::cout << "Int constructor called" << std::endl;
	_value = nb << Fixed::fractionnalBits;
}

Fixed::Fixed(const float nb)
{
	// std::cout << "Float constructor called" << std::endl;
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

//********* Booléen *********//

bool Fixed::operator!=(const Fixed &other) const
{
	return (this->getRawBits() != other.getRawBits());
}

bool Fixed::operator==(const Fixed &other) const
{
	return (this->getRawBits() == other.getRawBits());
}

bool Fixed::operator<(const Fixed &other) const
{
	return (this->getRawBits() < other.getRawBits());
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (this->getRawBits() <= other.getRawBits());
}

bool Fixed::operator>(const Fixed &other) const
{
	return (this->getRawBits() > other.getRawBits());
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (this->getRawBits() >= other.getRawBits());
}

//********* Basique *********//

Fixed Fixed::operator+(const Fixed &other)
{
	Fixed val(*this);

	val.setRawBits(this->getRawBits() + other.getRawBits());
	return (val);
}

Fixed Fixed::operator-(Fixed const &other)
{
	Fixed val(*this);

	val.setRawBits(this->getRawBits() - other.getRawBits());
	return (val);
}

Fixed Fixed::operator*(Fixed const &other)
{
	Fixed val(*this);
	long tmp1, tmp2;

	tmp1 = ((long)this->getRawBits());
	tmp2 = ((long)other.getRawBits());
	val.setRawBits((tmp1 * tmp2) / (1 << Fixed::fractionnalBits));
	return (val);
}

Fixed Fixed::operator/(Fixed const &other)
{
	Fixed val(*this);
	long tmp1, tmp2;

	tmp1 = ((long)this->getRawBits());
	tmp2 = ((long)other.getRawBits());
	val.setRawBits((tmp1 * (1 << Fixed::fractionnalBits)) / tmp2);
	return (val);
}

//********* Incrementation *********//

Fixed Fixed::operator++()
{
	this->_value++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return (tmp);
}

Fixed Fixed::operator--()
{
	this->_value--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return (tmp);
}

//****************************************************//
//                                                    //
//                      Min/Max                       //
//                                                    //
//****************************************************//

Fixed const &Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{	
	if (a > b)
		return (a);
	return (b);
}

Fixed const &max(Fixed const &a, Fixed const &b)
{
	return  (Fixed::max(a, b));
}

Fixed &max(Fixed &a, Fixed &b)
{	
	return  (Fixed::max(a, b));
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed const &min(Fixed const &a, Fixed const &b)
{
	return (Fixed::min(a, b));
}

Fixed &min(Fixed &a, Fixed &b)
{
	return (Fixed::min(a,b));
}
