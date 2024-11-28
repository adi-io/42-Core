#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string givenName, int i) : name(givenName)
{
    if (i < 1)
        throw GradeTooHighException();
    if (i > 150)
        throw GradeTooLowException();

    rank = i;
    std::cout << "A Bureaucrat is born & rank is successfully assigned" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << this->name << " Bureaucrat is terminated" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), rank(other.rank)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
    {
        this->rank = other.rank;
        std::cout << "Bureaucrat copy assignment operator called" << std::endl;
    }
    return *this;
}

std::string	Bureaucrat::getName() const
{
	return name;
}

int	Bureaucrat::getRank() const
{
	return rank;
}

void Bureaucrat::promoteBureaucrat()
{
    if (rank-1 < 1)
        throw GradeTooHighException();
    if (rank-1 > 150)
        throw GradeTooLowException();

    rank++;
    std::cout << "Promotion granted" << std::endl;
}

void Bureaucrat::demoteBureaucrat()
{
    if (rank+1 > 150)
        throw GradeTooLowException();
    if (rank+1 < 0)
        throw GradeTooHighException();

    rank--;
    std::cout << "Demotion executed" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getRank();
    return os;
}
