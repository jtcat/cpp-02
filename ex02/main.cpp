#include "Fixed.h"
#include <iostream>

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << Fixed(-10.4f).toInt() << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;
	std::cout << "4 / 2: " << Fixed(4) / Fixed(2) << std::endl;
	std::cout << "5 / 2: " << Fixed(5) / Fixed(2) << std::endl;
	std::cout << "-5 / 2: " << Fixed(-5) / Fixed(2) << std::endl;
	std::cout << "-10 / 3: " << Fixed(-10) / Fixed(3) << std::endl;

	std::cout << "5.01 > 5.0: " << (Fixed(5.01f) > Fixed(5.0f)) << std::endl;
	std::cout << "5.0 == 5.0: " << (Fixed(5.0f) == Fixed(5.0f)) << std::endl;

	std::cout << "120.53 - -200: " << (Fixed(120.53f) - Fixed(-200)) << std::endl;

	std::cout << "-3541.81 + 4000: " << (Fixed(-3541.81f) + Fixed(4000)) << std::endl;
	return 0;
}
