//#pragma once

#ifndef AFORMS_HPP
#define AFORMS_HPP

#include <string>

class	PresidentialPardonForm;
class	ShrubberyCreationForm;
class	RobotomyRequestForm;
class	Bureaucrat;

class	AForms
{
	private:
		const std::string	name;
		bool	val;
		const int	grade;
		const int	oGrade;

	public:
		std::string	signatory;
		AForms(const std::string gName, const int gGrade, const int gOGrade);
		void	signForm(Bureaucrat &chap);
		void	beSigned(Bureaucrat &chap);
		virtual void	action() const = 0;
		void	execute(Bureaucrat const &executor) const;
};

#endif
