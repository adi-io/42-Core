#include "Intern.hpp"
#include <cstring>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << "Intern has been created" << std::endl;
}

AForms*	Intern::makeForm(std::string name, std::string target)
{
	try
	{
		if (name == "ShrubberyCreationForm")
			return (new ShrubberyCreationForm(target));
		else if (name == "RobotomyRequestForm")
			return (new RobotomyRequestForm(target));
		else if (name == "PresidentialPardonForm")
			return (new PresidentialPardonForm(target));
		else
			throw std::runtime_error("Please enter a valid form name");
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
		return (nullptr);
	}
}
