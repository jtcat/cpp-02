#include "Fixed.h"

Fixed::Fixed(void): _rawbits(0) {
	//std::cout << "Default constructor called" << std::endl;
}	

Fixed::Fixed(const int val) {
	_rawbits = val << _dec_point;
}

Fixed::Fixed(const float val) {
	_rawbits = roundf(val * (1 << _dec_point));
}

Fixed::Fixed(Fixed const &ref) {
	_rawbits = ref._rawbits;
	//std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed(void) {
	//std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) {
	//std::cout << "getRawBits member function called" << std::endl;
	return _rawbits;
}

void	Fixed::setRawBits(const int raw) {
	_rawbits = raw;
}

// _rawbits >> _dec_point "rounds" down, i.e floors.
// By adding half of a unit we can round up and still be relatively fast
int		Fixed::toInt(void) const {
	return (_rawbits + (1 << (_dec_point - 1))) >> _dec_point;
}

float	Fixed::toFloat(void) const{
	return float(_rawbits) / (1 << _dec_point);
}

Fixed&	Fixed::operator=(Fixed const& ref) {
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &ref)
		_rawbits = ref._rawbits;
	return *this;
}

std::ostream&	operator<<(std::ostream& out, const Fixed& num) {
	out << num.toFloat();
	return out;
}

bool	Fixed::operator>(const Fixed& ref) const{
	return _rawbits > ref._rawbits;
}

bool	Fixed::operator<(const Fixed& ref) const{
	return _rawbits < ref._rawbits;
}

bool	Fixed::operator>=(const Fixed& ref) const{
	return _rawbits >= ref._rawbits;
}

bool	Fixed::operator<=(const Fixed& ref) const{
	return _rawbits <= ref._rawbits;
}

bool	Fixed::operator==(const Fixed& ref) const{
	return _rawbits == ref._rawbits;
}

bool	Fixed::operator!=(const Fixed& ref) const{
	return _rawbits != ref._rawbits;
}

Fixed	Fixed::operator+(const Fixed& ref) const{
	Fixed	res;

	res.setRawBits(_rawbits + ref._rawbits);
	return (res);
}

Fixed	Fixed::operator-(const Fixed& ref) const{
	Fixed	res;

	res.setRawBits(_rawbits - ref._rawbits);
	return (res);
}

Fixed	Fixed::operator*(const Fixed &ref) const{
	Fixed	res;
	int64_t prod = (int64_t)_rawbits * (int64_t)ref._rawbits;

	res._rawbits = (int32_t)((prod >> _dec_point) + ((prod >> (_dec_point - 1)) & 1));
	return res;
}

Fixed	Fixed::operator/(const Fixed &ref) const{
	Fixed	fdiv;
	int64_t	div = (static_cast<int64_t>(_rawbits) << 32) / static_cast<int64_t>(ref._rawbits);

	fdiv.setRawBits(static_cast<int32_t>(div >> (32 - _dec_point)));
	return fdiv;
}

Fixed&	Fixed::operator++(void) {
	++_rawbits;
	return *this;
}

Fixed	Fixed::operator++(int) {
	Fixed tmp = *this;

	++(*this);
	return tmp;
}

Fixed&	Fixed::operator--(void) {
	--_rawbits;
	return *this;
}

Fixed	Fixed::operator--(int) {
	Fixed tmp = *this;

	--(*this);
	return tmp;
}

Fixed&	Fixed::min(Fixed &a, Fixed &b) {
	return (a <= b) ? a : b;
}

const Fixed&	Fixed::min(Fixed const &a, Fixed const &b) {
	return (a <= b) ? a : b;
}

Fixed&	Fixed::max(Fixed &a, Fixed &b) {
	return (a >= b) ? a : b;
}

const Fixed&	Fixed::max(Fixed const &a, Fixed const &b) {
	return (a >= b) ? a : b;
}
