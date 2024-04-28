#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class	Fixed
{
	private:
		int	fixPointNumber;
		static const int	FrBits;

	public:
		Fixed(void);
		Fixed(const int nbr);
		Fixed(const float nbr);

		~Fixed(void);

		Fixed &operator= (const Fixed &rhs);

		bool operator== (const Fixed &rhs) const;
		bool operator< (const Fixed &rhs) const;
		bool operator> (const Fixed &rhs) const;
		bool operator<= (const Fixed &rhs) const;
		bool operator>= (const Fixed &rhs) const;

		Fixed operator+ (const Fixed &rhs);
		Fixed operator- (const Fixed &rhs);
		Fixed operator* (const Fixed &rhs);
		Fixed operator/ (const Fixed &rhs);

		Fixed &operator++ ();
		Fixed operator++ (int);
		Fixed &operator-- ();
		Fixed operator-- (int);

		Fixed(const Fixed &c);

		int	getRawBits(void) const;
		void	setRawBits(int const raw);
		int	toInt(void) const;
		float	toFloat(void) const;

		static Fixed	&min(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static Fixed	&max(Fixed &a, Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);
};

		std::ostream &operator<<(std::ostream &o, Fixed const &instance);
#endif
