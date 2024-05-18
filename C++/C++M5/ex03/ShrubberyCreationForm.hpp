#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Bureaucrat.hpp"
#include "AForms.hpp"
#include <fstream>

class	ShrubberyCreationForm : public AForms
{
	private:
		std::string	target;
	public:
		ShrubberyCreationForm(const std::string gName);
		void	action() const;
};

#endif
