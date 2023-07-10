#include "Fixed.hpp"

Fixed::Fixed()
{
	value = 0;
}

Fixed::Fixed(Fixed &t)
{
	value = t.value;
}

Fixed::Fixed(const Fixed &t)
{
	value = t.value;
}

Fixed::Fixed(const int val)
{
	int scale;

	scale = 1 << fraction;
	value = val * scale;
}

Fixed::Fixed(const float val)
{
	int scale;

	scale = 1 << fraction;
	value = static_cast<int>(roundf(val * scale));
}

Fixed::~Fixed()
{
}

Fixed &Fixed::operator=(const Fixed &t)
{
	value = t.value;
	return *this;
}

void	Fixed::setValueFromFloat(float val)
{
	int scale;

	scale = 1 << fraction;
	value = static_cast<int>(roundf(val * scale));
}

int Fixed::getRawBits(void) const
{
	return (value);
}

void Fixed::setRawBits(int const raw)
{
	value = raw;
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

Fixed	Fixed::operator+(const Fixed &t)
{
	Fixed result;
	result.setRawBits(this->getRawBits() + t.getRawBits());
	return result;
}

Fixed	Fixed::operator-(const Fixed &t)
{
	Fixed result;
	result.setRawBits(this->getRawBits() - t.getRawBits());
	return result;
}
Fixed	Fixed::operator*(const Fixed &t)
{
	Fixed result(this->toFloat() * t.toFloat());
	return result;
}
Fixed	Fixed::operator/(const Fixed &t)
{
	Fixed result(this->toFloat() / t.toFloat());
	return result;
}

bool	Fixed::operator==(const Fixed &t)
{
	if (this->value == t.getRawBits())
		return (true);
	return (false);
}
bool	Fixed::operator!=(const Fixed &t)
{
	if (this->value != t.getRawBits())
		return (true);
	return (false);
}
bool	Fixed::operator<(const Fixed &t)
{
	if (this->value < t.getRawBits())
		return (true);
	return (false);
}
bool	Fixed::operator>(const Fixed &t)
{
	if (this->value > t.getRawBits())
		return (true);
	return (false);
}
bool	Fixed::operator<=(const Fixed &t)
{
	if (this->value <= t.getRawBits())
		return (true);
	return (false);
}
bool	Fixed::operator>=(const Fixed &t)
{
	if (this->value >= t.getRawBits())
		return (true);
	return (false);
}

Fixed	Fixed::operator++()
{
	Fixed	temp;
	temp.setRawBits(++value);
	return (temp);
}
Fixed	Fixed::operator--()
{
	Fixed	temp;
	temp.setRawBits(--value);
	return (temp);
}
Fixed	Fixed::operator++(int)
{
	Fixed	temp;
	temp.setRawBits(value++);
	return (temp);
}
Fixed	Fixed::operator--(int)
{
	Fixed	temp;
	temp.setRawBits(value--);
	return (temp);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}
