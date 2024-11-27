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

void Bureaucrat::promoteBureaucrat(int i)
{
    if (i < 1)
        throw GradeTooHighException();
    if (i >= rank)
        throw std::runtime_error("Cannot promote to a lower grade");

    rank = i;
    std::cout << "Promotion granted" << std::endl;
}

void Bureaucrat::demoteBureaucrat(int i)
{
    if (i > 150)
        throw GradeTooLowException();
    if (i <= rank)
        throw std::runtime_error("Cannot demote to a higher grade");

    rank = i;
    std::cout << "Demotion executed" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getRank();
    return os;
}

void Bureaucrat::signForm(AForm& form) {
    try {
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << name << " couldn't sign " << form.getName()
                 << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form) const {
    try {
        form.execute(*this);
        std::cout << name << " executed " << form.getName() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << name << " couldn't execute " << form.getName()
                 << " because " << e.what() << std::endl;
    }
}
