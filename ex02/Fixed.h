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

		Fixed&	operator=(Fixed const &ref);

		bool	operator>(Fixed const &ref) const;
		bool	operator<(Fixed const &ref) const;
		bool	operator>=(Fixed const &ref) const;
		bool	operator<=(Fixed const &ref) const;
		bool	operator==(Fixed const &ref) const;
		bool	operator!=(Fixed const &ref) const;

		Fixed	operator+(Fixed const &ref) const;
		Fixed	operator-(Fixed const &ref) const;
		Fixed	operator*(Fixed const &ref) const;
		Fixed	operator/(Fixed const &ref) const;

		// Pre-increment
		Fixed&	operator++();
		// Post-increment
		Fixed	operator++(int);
		// Pre-decrement
		Fixed&	operator--();
		// Post-decrement
		Fixed	operator--(int);

		friend std::ostream &operator<<(std::ostream &out, const Fixed &num);

		static Fixed&		min(Fixed &a, Fixed &b);
		static const Fixed&	min(Fixed const &a, Fixed const &b);
		static Fixed&		max(Fixed &a, Fixed &b);
		static const Fixed&	max(Fixed const &a, Fixed const &b);
				

		float	toFloat(void)	const;
		int		toInt(void)	const;
		int		getRawBits(void);
		void	setRawBits(int const raw);
};

#endif
