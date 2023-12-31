#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed {
private:
	int	value;
	static const int fraction = 8;
public:
	Fixed();
	Fixed(Fixed &t);
	Fixed(const Fixed &t);
	~Fixed();
	Fixed(const int val);
	Fixed(const float val);
	Fixed&			operator=(const Fixed& t);
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream & operator<<( std::ostream & o, Fixed const & i );


#endif
