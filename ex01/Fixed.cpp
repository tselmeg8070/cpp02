#include "Fixed.hpp"

Fixed::Fixed()
{
	value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed &t)
{
	value = t.value;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &t)
{
	value = t.value;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int val)
{
	int scale;

	scale = 1 << fraction;
	value = val * scale;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float val)
{
	int scale;

	scale = 1 << fraction;
	value = static_cast<int>(roundf(val * scale));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &t)
{
	value = t.value;
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (value);
}

void Fixed::setRawBits(int const raw)
{
	value = raw;
	std::cout << "setRawBits member function called" << std::endl;
}

float Fixed::toFloat(void) const
{
	float scale;

	scale = 1 << fraction;
	return (static_cast<float>(value) / scale);
}
int Fixed::toInt(void) const
{
	int scale;

	scale = 1 << fraction;
	return (value / scale);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}
