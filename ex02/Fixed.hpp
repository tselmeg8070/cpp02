#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed {
private:
	int		value;
	static	const int fraction = 8;
	void	setValueFromFloat(float val);
public:
	Fixed();
	Fixed(Fixed &t);
	Fixed(const Fixed &t);
	~Fixed();
	Fixed(const int val);
	Fixed(const float val);
	Fixed&	operator=(const Fixed &t);

	Fixed	operator+(const Fixed &t);
	Fixed	operator-(const Fixed &t);
	Fixed	operator*(const Fixed &t);
	Fixed	operator/(const Fixed &t);

	bool	operator==(const Fixed &t);
	bool	operator!=(const Fixed &t);
	bool	operator<(const Fixed &t);
	bool	operator>(const Fixed &t);
	bool	operator<=(const Fixed &t);
	bool	operator>=(const Fixed &t);

	Fixed	operator++();
	Fixed	operator--();
	Fixed	operator++(int);
	Fixed	operator--(int);

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat(void) const;
	int		toInt(void) const;
	static Fixed& max(Fixed &a, Fixed &b);
	static const Fixed& max(const Fixed &a, const Fixed &b);
	static Fixed& min(Fixed &a, Fixed &b);
	static const Fixed& min(const Fixed &a, const Fixed &b);
};

std::ostream & operator<<( std::ostream & o, Fixed const & i );

#endif
