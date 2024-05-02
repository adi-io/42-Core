#include "Fixed.hpp"

Fixed::Fixed(void): nbr(0)
{
	std::cout << "Default constructer called" << std::endl;
}

Fixed::Fixed(Fixed &c)
{
	this->nbr = c.getRawBits();
	std::cout << "Copy constructer called" << std::endl;
}

Fixed &Fixed::operator= (Fixed &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->nbr = rhs.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Default destructer called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->nbr);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->nbr = raw;
}
