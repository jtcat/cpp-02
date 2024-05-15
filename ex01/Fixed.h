#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int					_rawbits;
		static const int	_dec_point = 8;

	public:
				Fixed(void);
				Fixed(const int val);
				Fixed(const float val);
				Fixed(Fixed const &ref);
				~Fixed(void);

		Fixed&					operator=(Fixed const &ref);
		friend std::ostream&	operator<<(std::ostream &out, const Fixed &num);

		float	toFloat(void)	const;
		int		toInt(void)	const;
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
