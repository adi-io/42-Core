//#pragma once

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP


#include <iostream>
#include <string>
#include "AForms.hpp"

class	AForm;

class	Bureaucrat
{
	public:
		const	std::string	name;
		int	rank;

		Bureaucrat(std::string givenName, int i);
		~Bureaucrat();
		std::string	getName();
		int	getRank();
		void	promoteBureaucrat(int i);
		void	demoteBureaucrat(int i);
		void	executeForm(AForms const &form);
};

#endif
