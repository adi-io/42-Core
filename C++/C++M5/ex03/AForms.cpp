#include "Bureaucrat.hpp"
#include "AForms.hpp"

void	AForms::execute(Bureaucrat const &executor) const
{
	try
	{
		if (this->val == false)
			throw std::runtime_error("Form not signed");
		else if (executor.rank > this->oGrade)
			throw std::runtime_error("GradeTooLowException");
		this->action();
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

}

AForms::AForms(const std::string gName, const int gGrade, const int gOGrade) : name(gName), val(false), grade(gGrade), oGrade(gOGrade)
{
	try
	{
		if (gGrade < 0)
			throw std::runtime_error("GradeTooHighException");
		else if (gGrade > 150)
			throw std::runtime_error("GradeTooHighException");
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

}

void	AForms::beSigned(Bureaucrat &chap)
{
	try
	{
		if (this->val == false && chap.rank > this->grade)
		{
			throw std::runtime_error("GradeTooLowToSignException");
			return ;
		}
		if (this->val == false && chap.rank > this->oGrade)
			throw std::runtime_error("GradeTooLowToAuthException");
		else
		{
			this->signatory = chap.name;
			this->val = true;
			std::cout << "Form " << this->name << " has been signed by " << chap.name << std::endl;
		}

	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void	AForms::signForm(Bureaucrat &chap)
{
	try
	{
		if (this->val == false)
			throw std::runtime_error("Form still unsigned");
		if (this->oGrade >= chap.rank)
			std::cout << "Form " << this->name << " has been signed by " << this->signatory << std::endl;
		else
			throw std::runtime_error("GradeTooLowToAuthException");
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}
