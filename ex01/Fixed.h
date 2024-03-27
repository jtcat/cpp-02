#ifndef FIXED_H
# define FIXED_H

class Fixed {
	private:
		int					_rawbits;
		static const int	_frac_bits = 8;
	public:
				Fixed(void);
				Fixed(const int rawbits);
				Fixed(const float rawbits);
				Fixed(Fixed &ref);
				Fixed &operator=(Fixed &ref);
				~Fixed(void);

		float	toFloat(void)	const;
		int		toInt(void)	const;
		int		getRawBits(void);
		void	setRawBits(int const raw);
};

#endif
