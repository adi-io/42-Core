#include "Bureaucrat.hpp"
#include "AForms.hpp"
#include <fstream>

class	ShrubberyCreationForm : public AForm
{
	private:
		std::string	target;
	public:
		ShrubberyCreationForm(const std::string gName);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        ~ShrubberyCreationForm();
        void execute(Bureaucrat const & executor) const;
		void	action() const;
};
