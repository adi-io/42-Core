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
		Fixed(const Fixed &c);

		int	getRawBits(void) const;
		void	setRawBits(int const raw);
		int	toInt(void) const;
		float	toFloat(void) const;
};

		std::ostream &operator<<(std::ostream &o, Fixed const &instance);
#endif
