#include "Bureaucrat.hpp"
#include "AForms.hpp"

void	Bureaucrat::executeForm(AForms const &form)
{
	try
	{
		form.execute(*this);

	}
	catch (const std::exception& e)
	{
		std::cout << this->name << " Could not sign the form because" << "Exception: " << e.what() << std::endl;
	}
}

Bureaucrat::Bureaucrat( std::string givenName, int i) : name(givenName)
{
	try
	{
		if (i <= 150 && i > 0)
		{
			this->rank  = i;
			std::cout << "A Bureaucrat is born & rank is successfully assigned" << std::endl;
		}
		else
		{
			if (i < 1)
				throw std::runtime_error("GradeTooHighException");
			if (i > 150)
				throw std::runtime_error("GradeTooLowException");
		}

	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

Bureaucrat::~Bureaucrat()
{
	std::cout << this->name << " Bureaucrat is terminated" << std::endl;
}

std::string	Bureaucrat::getName()
{
	return (this->name);
}

int	Bureaucrat::getRank()
{
	return (this->rank);
}

void	Bureaucrat::promoteBureaucrat(int i)
{
	try
	{
		if (i < 1)
		{
			throw std::runtime_error("invalid");
		}
		if (i > this->rank)
		{
			throw std::runtime_error("rank");
		}
		else
		{
			this->rank = i;
			std::cout << "Promotion granted" << std::endl;
		}
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}
