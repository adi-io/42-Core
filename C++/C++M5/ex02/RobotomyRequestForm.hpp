#include "Bureaucrat.hpp"
#include "AForms.hpp"

class	RobotomyRequestForm : public AForms
{
	private:
		std::string	target;
	public:
		RobotomyRequestForm(const std::string gName);
		void	action() const;
};
