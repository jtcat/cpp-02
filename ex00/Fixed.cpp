#include "Fixed.h"
#include <iostream>

Fixed::Fixed(void): _rawbits(0) {
	std::cout << "Default constructor called" << std::endl;
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
