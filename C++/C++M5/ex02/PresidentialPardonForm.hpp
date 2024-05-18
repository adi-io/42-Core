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
