#include "Bureaucrat.hpp"

class	Forms
{
	private:
		const std::string	name;
		bool	val;
		const int	grade;
		const int	oGrade;

	public:
		std::string	signatory;
		Forms(const std::string gName, const int gGrade, const int gOGrade);
		void	signForm(Bureaucrat &chap);
		void	beSigned(Bureaucrat &chap);
};
