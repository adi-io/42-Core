#pragma once

#include "AForms.hpp"
#include "Bureaucrat.hpp"

class AForms;

class	Intern
{
	public:
		Intern();
		AForms*	makeForm(std::string name, std::string target);
};
