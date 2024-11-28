#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "AForms.hpp"

class	Bureaucrat
{

    private:
        const std::string name;
        int rank;

	public:

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
		void	promoteBureaucrat();
		void	demoteBureaucrat();
		void signForm(AForm& form);
		void executeForm(AForm const & form) const;

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
