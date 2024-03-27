#ifndef FIXED_H
# define FIXED_H

#include <iostream>

#define FLOAT_MASK_MANTISSA
#define FLOAT_OFFSET_MANTISSA 9
#define FLOAT_EXPONENT_BIAS 127
#define FLOAT_WIDTH_EXPONENT 8
#define FLOAT_WIDTH_MANTISSA 23
#define FLOAT_EXPONENT(val) ((val << 1) >> (32 - FLOAT_WIDTH_EXPONENT)) - 127

union int_float {int i; float f;};

class Fixed {
	private:
		int					_rawbits;
		static const int	_dec_point = 8;
	public:
				Fixed(void);
				Fixed(const int val);
				Fixed(const float val);
				Fixed(Fixed &ref);
				Fixed &operator=(Fixed &ref);
				~Fixed(void);
				friend std::ostream &operator<<(std::ostream &out, const Fixed &num);

		float	toFloat(void)	const;
		int		toInt(void)	const;
		int		getRawBits(void);
		void	setRawBits(int const raw);
};

#endif
