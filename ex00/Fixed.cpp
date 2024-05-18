#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void): _rawbits(0) {
	std::cout << "Default constructor called" << std::endl;
}	

Fixed::Fixed(Fixed &ref) {
	std::cout << "Copy constructor called" << std::endl;
	*this = ref;
}

Fixed &Fixed::operator=(Fixed &ref) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (&ref != this)
		_rawbits = ref.getRawBits();
	return *this;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return _rawbits;
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	_rawbits = raw;
}
