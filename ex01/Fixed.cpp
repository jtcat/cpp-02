#include "Fixed.h"
#include <iostream>
#include <strstream>
#include <math.h>

Fixed::Fixed(void): _rawbits(0) {
	std::cout << "Default constructor called" << std::endl;
}	

Fixed::Fixed(int val) {
	_rawbits = val << _dec_point;
}

Fixed::Fixed(float val) {
	int_float conv = {.f = val};
	int exponent = FLOAT_EXPONENT(conv.i);

	// Float order of magnitude is too small to be representable
	if (exponent < -(sizeof(Fixed::_rawbits) * 8 - 1))
		
}

Fixed::Fixed(Fixed &ref) {
	_rawbits = ref._rawbits;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed &ref) {
	_rawbits = ref._rawbits;
	std::cout << "Copy assignment operator called" << std::endl;
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

int		Fixed::toInt(void) const{
	return _rawbits >> _dec_point;
}

float	Fixed::toFloat(void) const{
	if (_rawbits == 0)
		return 0.0f;
	// Write sign
	int_float conv = {.i = _rawbits & (1 << 31)};
	// Discards least significant bits
	if (conv.i)
		// Number is negative, convert from complement of 2
		conv.i |= (~_rawbits + 1) >> FLOAT_WIDTH_EXPONENT;
	else
		conv.i |= _rawbits >> FLOAT_WIDTH_EXPONENT;
	// -dec_point is always larger than -32, hence
	// -dec_point + 127 is always positive, no uint conversion
	// necessary
	// Write exponent
	conv.i |= (-_dec_point + 127) << FLOAT_WIDTH_MANTISSA;
	return conv.f;
}

std::ostream&	operator<<(std::ostream& out, const Fixed& num) {
	if (num._rawbits & (1 << 31)) {
		out << '-';
		out << (int)((~num._rawbits + 1) >> num._dec_point);
	}
	else
		out << (int)(num._rawbits >> num._dec_point);
	out << '.' << (int)(num._rawbits << (32 - num._dec_point) >> num._dec_point);
	return out;
}
