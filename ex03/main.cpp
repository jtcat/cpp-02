#include "Point.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "point in trig: "
		<< bsp(Point(-3.26f, 2.36f), Point(0.86f, -4.34f), Point(4.32f, 3.62), Point(2.94f, 2.6f))
		<< std::endl;
}
