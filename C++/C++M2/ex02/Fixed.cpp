#include "Fixed.hpp"

const int	Fixed::FrBits = 8;

Fixed	&Fixed::operator++ ()
{
	this->fixPointNumber++;
	return (*this);
}

Fixed	Fixed::operator++ (int)
{
	Fixed temp = *this;
	this->fixPointNumber++;
	return (temp);
}

Fixed	&Fixed::operator-- ()
{
	this->fixPointNumber--;
	return (*this);
}

Fixed	Fixed::operator-- (int)
{
	Fixed temp = *this;
	this->fixPointNumber--;
	return (temp);
}


Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a.fixPointNumber < b.fixPointNumber)
		return (a);
	else
		return (b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.fixPointNumber < b.fixPointNumber)
		return (a);
	else
		return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a.fixPointNumber > b.fixPointNumber)
		return (a);
	else
		return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.fixPointNumber > b.fixPointNumber)
		return (a);
	else
		return (b);
}

Fixed	Fixed::operator+ (const Fixed &rhs)
{
	return (Fixed(this->fixPointNumber + rhs.fixPointNumber));
}

Fixed	Fixed::operator- (const Fixed &rhs)
{
	return (Fixed(this->fixPointNumber - rhs.fixPointNumber));
}

Fixed	Fixed::operator* (const Fixed &rhs)
{
	Fixed temp;

	temp.setRawBits( (long long)this -> getRawBits() * (long long)rhs.getRawBits() >> FrBits );
	return (temp);
}

Fixed	Fixed::operator/ (const Fixed &rhs)
{
	Fixed temp;

	temp.setRawBits( (long long)this -> getRawBits() << FrBits / rhs.getRawBits() );
	return (temp);
}

bool	Fixed::operator== (const Fixed &rhs) const
{
	if (this->fixPointNumber == rhs.fixPointNumber)
		return (true);
	return (false);
}

bool	Fixed::operator< (const Fixed &rhs) const
{
	if (this->fixPointNumber < rhs.fixPointNumber)
		return (true);
	return (false);
}

bool	Fixed::operator> (const Fixed &rhs) const
{
	if (this->fixPointNumber> rhs.fixPointNumber)
		return (true);
	return (false);
}

bool	Fixed::operator<= (const Fixed &rhs) const
{
	if (this->fixPointNumber <= rhs.fixPointNumber)
		return (true);
	return (false);
}

bool	Fixed::operator>= (const Fixed &rhs) const
{
	if (this->fixPointNumber >= rhs.fixPointNumber)
		return (true);
	return (false);
}

Fixed::Fixed(void): fixPointNumber(0)
{
	std::cout << "Default constructer called" << std::endl;
}

Fixed::Fixed(const int nbr)
{
	std::cout << "Int constructer called" << std::endl;
	this->fixPointNumber = nbr << this->FrBits;
}

Fixed::Fixed(const float  nbr)
{
	std::cout << "Float constructer called" << std::endl;
	this->fixPointNumber = roundf(nbr * (1 << this->FrBits));
}

Fixed::Fixed(const Fixed &c)
{
	this->fixPointNumber = c.getRawBits();
	std::cout << "Copy constructer called" << std::endl;
}

Fixed &Fixed::operator= (const Fixed &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->fixPointNumber = rhs.getRawBits();
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
	return (this->fixPointNumber);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fixPointNumber = raw;
}

int	Fixed::toInt(void) const
{
	return (this->fixPointNumber >> this->FrBits);
}

float	Fixed::toFloat(void) const
{
	return ((float)(this->fixPointNumber) / (float)(1 << this->FrBits));
}

std::ostream &operator<<(std::ostream &o, Fixed const &instance)
{
	o << instance.toFloat();
	return (o);
}
