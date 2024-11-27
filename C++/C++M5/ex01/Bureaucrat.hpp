#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "Forms.hpp"

class	Bureaucrat
{
	public:
		const	std::string	name;
		int	rank;

		class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Grade is too high";
                }
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Grade is too low";
                }
        };

		Bureaucrat(const std::string givenName, int i);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		std::string	getName() const;
		int	getRank() const;
		void	promoteBureaucrat(int i);
		void	demoteBureaucrat(int i);
		void signForm(Form& form);

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
