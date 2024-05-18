#include "Point.hpp"
#include <iostream>

Point::Point(void): _x(Fixed(0)), _y(Fixed(0)) {
	std::cout << "Point default constructor called" << std::endl;
}

Point::~Point(void) {
	std::cout << "Point destructor called" << std::endl;
}

Point::Point(const Point& src): _x(Fixed(src._x)), _y(Fixed(src._y)) {
	std::cout << "Point copy constructor called" << std::endl;
}

Point::Point(const float a, const float b): _x(Fixed(a)), _y(Fixed(b)) {
	std::cout << "Point float constructor called" << std::endl;
}

Point::Point(const Fixed a, const Fixed b): _x(a), _y(b) {
	std::cout << "Point Fixed constructor called" << std::endl;
}

Point&	Point::operator=(const Point &src) {
	std::cout << "Point assignment operator called" << std::endl;
	(void)src;
	return *this;
}

Point	Point::operator+(const Point& other) const {
	std::cout << "Point sum operator called" << std::endl;
	return (Point(_x + other._x, _y + other._y));
}

Point	Point::operator-(const Point& other) const {
	std::cout << "Point difference operator called" << std::endl;
	return (Point(_x + other._x, _y + other._y));
}

Point	Point::operator*(const float factor) const {
	std::cout << "Point difference operator called" << std::endl;
	return (Point(_x * factor, _y * factor));
}

Point	Point::operator/(const float factor) const {
	std::cout << "Point difference operator called" << std::endl;
	return (Point(_x / factor, _y / factor));
}

const Fixed&	Point::x(void) const {
	return _x;
}

const Fixed&	Point::y(void) const {
	return _y;
}
