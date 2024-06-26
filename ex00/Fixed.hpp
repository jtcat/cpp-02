#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
	private:
		int					_rawbits;
		static const int	_frac_bits = 8;

	public:
				Fixed(void);
				Fixed(Fixed &ref);
				Fixed &operator=(Fixed &ref);
				~Fixed(void);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
