#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "AForms.hpp"


PresidentialPardonForm::PresidentialPardonForm(const std::string gName) : AForms("PresidentialPardonForm", 25, 5)
{
	this->target = gName;
}

void	PresidentialPardonForm::action() const
{
	std::cout << this->target << "has been pardoned by Zaphod Beeblebrox" << std::endl;
}
