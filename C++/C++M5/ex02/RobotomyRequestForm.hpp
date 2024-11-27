#include "Bureaucrat.hpp"
#include "AForms.hpp"

class	RobotomyRequestForm : public AForm
{
	private:
		std::string	target;
	public:
		RobotomyRequestForm(const std::string gName);
		RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        void execute(Bureaucrat const & executor) const;
        ~RobotomyRequestForm();
		void	action() const;
};
