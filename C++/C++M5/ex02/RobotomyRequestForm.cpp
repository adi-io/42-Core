#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "AForms.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string gName) : AForm("RobotomyRequestForm", 72, 45)
{
	this->target = gName;
}


RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), target(other.target)
{
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
        std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void	RobotomyRequestForm::action() const
{
	std::cout << "drrrrrrrrrrrrrrr" << std::endl;
	try
	{
		if ( (rand() % 100) % 2 == 0)
			std::cout << this->target <<  " robotomized successfully" << std::endl;
		else
			throw std::runtime_error("Robotomy failed");
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    AForm::execute(executor);
    this->action();
}
