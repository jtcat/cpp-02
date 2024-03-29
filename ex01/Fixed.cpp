#include "Fixed.h"

Fixed::Fixed(void): _rawbits(0) {
	std::cout << "Default constructor called" << std::endl;
}	

Fixed::Fixed(const int val) {
	std::cout << "Int constructor called" << std::endl;
	_rawbits = val << _dec_point;
}

Fixed::Fixed(const float val) {
	std::cout << "Float constructor called" << std::endl;
	_rawbits = roundf(val * (1 << _dec_point));
}

Fixed::Fixed(Fixed const &ref) {
	std::cout << "Copy constructor called" << std::endl;
	_rawbits = ref._rawbits;
}

Fixed&	Fixed::operator=(Fixed const&ref) {
	std::cout << "Copy assignment operator called" << std::endl;
	_rawbits = ref._rawbits;
	return *this;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) {
	std::cout << "getRawBits member function called" << std::endl;
	return _rawbits;
}

void	Fixed::setRawBits(int const raw) {
	_rawbits = raw;
}

// _rawbits >> _dec_point "rounds" down, i.e floors.
// By adding half of a unit we can round up and still be relatively fast
int		Fixed::toInt(void) const {
	return (_rawbits + (1 << (_dec_point - 1))) >> _dec_point;
}

float	Fixed::toFloat(void) const {
	return float(_rawbits) / (1 << _dec_point);
}

std::ostream&	operator<<(std::ostream& out, const Fixed& num) {
	return out << num.toFloat();
}
