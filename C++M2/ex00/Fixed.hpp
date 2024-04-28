#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class	Fixed
{
	private:
		int	nbr;
		static const int	i = 8;

	public:
		Fixed(void);
		~Fixed(void);
		Fixed &operator= (Fixed &rhs);
		Fixed(Fixed &c);
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
