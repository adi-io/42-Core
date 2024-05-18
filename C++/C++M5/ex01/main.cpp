#include "Bureaucrat.hpp"
#include "Forms.hpp"

int	main(void)
{
	Bureaucrat	obj("Adi", 10);
	Bureaucrat	nobj("Paav", 2);
	Forms	fobj("A", 5, 5);
	fobj.beSigned(obj);
	fobj.signForm(nobj);

	return (0);
}
