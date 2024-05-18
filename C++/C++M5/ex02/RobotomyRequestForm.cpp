#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "AForms.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string gName) : AForms("RobotomyRequestForm", 72, 45)
{
	this->target = gName;
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
