#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class	Point {
	private:
		const Fixed	_x;
		const Fixed	_y;

	public:
		Point(void);
		~Point(void);
		Point(const Point& src);
		Point(const float x, const float y);
		Point(const Fixed x, const Fixed y);

		Point&	operator=(const Point& src);

		Point	operator+(const Point& other) const;
		Point	operator-(const Point& other) const;

		float	dot(const Point& other) const;
		static float	dot(const Point& a, const Point& b);
};

#endif
