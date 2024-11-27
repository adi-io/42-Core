#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main()
{
    Intern someRandomIntern;

    AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf) {
        Bureaucrat boss("Boss", 1);
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
    }

    AForm* invalidForm = someRandomIntern.makeForm("invalid form", "target");
    if (invalidForm) {
        delete invalidForm;
    }
    return 0;
}
