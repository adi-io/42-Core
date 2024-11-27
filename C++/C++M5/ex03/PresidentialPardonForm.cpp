#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "AForms.hpp"


PresidentialPardonForm::PresidentialPardonForm(const std::string gName) : AForm("PresidentialPardonForm", 25, 5)
{
	this->target = gName;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm(other), target(other.target)
{
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
        std::cout << "PresidentialPardonForm copy assignment operator called" << std::endl;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

void	PresidentialPardonForm::action() const
{
	std::cout << this->target << "has been pardoned by Zaphod Beeblebrox" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    AForm::execute(executor);
    this->action();
}
