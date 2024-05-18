#include "Point.hpp"

bool	bsp(const Point a, const Point b, const Point c, const Point point) {
	const Fixed	area = Fixed(0.5f) * (-b.y() * c.x() + a.y() * (-b.x() + c.x()) + a.x() * (b.y() - c.y()) + b.x() * c.y());
	const Fixed	s = Fixed(1) / (Fixed(2) * area) * (a.y() * c.x() - a.x() * c.y() + (c.y() - a.y()) * point.x() + (a.x() - c.x()) * point.y());
	const Fixed	t = Fixed(1) / (Fixed(2) * area) * (a.x() * b.y() - a.y() * b.x() + (a.y() - b.y()) * point.x() + (b.x() - a.x()) * point.y());

	std::cout << "trig area: " << area << std::endl;

	return s > Fixed(0) && t > Fixed(0) && (Fixed(1) - s - t) > Fixed(0);
}
