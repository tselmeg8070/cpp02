#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed {
private:
	int	value;
	static const int fraction = 8;
public:
	Fixed();
	Fixed(Fixed &t);
	~Fixed();
	Fixed& operator=(const Fixed& t);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif
