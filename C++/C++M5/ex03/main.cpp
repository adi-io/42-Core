#include "Bureaucrat.hpp"
#include "AForms.hpp"
#include "Intern.hpp"

int	main(void)
{
	AForms* rrf;
	Bureaucrat	obj("Adi", 10);
	Intern	newa;
	rrf = newa.makeForm("PresidentialPardonForm", "MOD");
	rrf->action();
	delete	rrf;
	return (0);
}
