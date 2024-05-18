#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Bureaucrat.hpp"
#include "AForms.hpp"

class	PresidentialPardonForm : public AForms
{
	private:
		std::string	target;
	public:
		void	action() const;
		PresidentialPardonForm(const std::string gName);
};

#endif
