#include "Bureaucrat.hpp"
#include "Forms.hpp"

int main() {
    try {
        Bureaucrat highRank("John", 1);
        Bureaucrat lowRank("Bob", 150);

        Form form1("Tax Form", 50, 25);
        Form form2("Top Secret", 1, 1);

        std::cout << form1 << std::endl << std::endl;
        std::cout << form2 << std::endl << std::endl;

        // Test signing forms
        highRank.signForm(form1);  // Should succeed
        lowRank.signForm(form2);   // Should fail

        // Display updated form status
        std::cout << form1 << std::endl;

        // Test form copying
        Form form3(form1);
        std::cout << form3 << std::endl;

    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
