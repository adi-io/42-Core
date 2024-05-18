#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class	Bureaucrat
{
	public:
		const	std::string	name;
		int	rank;

		Bureaucrat(const std::string givenName, int i);
		~Bureaucrat();
		std::string	getName();
		int	getRank();
		void	promoteBureaucrat(int i);
		void	demoteBureaucrat(int i);
};


#endif
