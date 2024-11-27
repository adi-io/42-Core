#include "Bureaucrat.hpp"
#include "AForms.hpp"

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try {
        // Create bureaucrats with different grades
        Bureaucrat president("President", 1);
        Bureaucrat manager("Manager", 70);
        Bureaucrat intern("Intern", 140);

        // Test ShrubberyCreationForm
        std::cout << "\n=== Testing ShrubberyCreationForm ===" << std::endl;
        ShrubberyCreationForm shrub("garden");
        intern.signForm(shrub);       // Should work
        intern.executeForm(shrub);    // Should work

        // Test RobotomyRequestForm
        std::cout << "\n=== Testing RobotomyRequestForm ===" << std::endl;
        RobotomyRequestForm robotomy("target1");
        manager.signForm(robotomy);   // Should work
        manager.executeForm(robotomy); // Should work

        // Test multiple robotomy attempts
        for (int i = 0; i < 5; i++) {
            std::cout << "\nAttempt " << i + 1 << ":" << std::endl;
            manager.executeForm(robotomy);
        }

        // Test PresidentialPardonForm
        std::cout << "\n=== Testing PresidentialPardonForm ===" << std::endl;
        PresidentialPardonForm pardon("criminal");
        manager.signForm(pardon);     // Should fail (grade too low)
        president.signForm(pardon);   // Should work
        president.executeForm(pardon); // Should work

        // Test executing unsigned form
        std::cout << "\n=== Testing Unsigned Form ===" << std::endl;
        PresidentialPardonForm unsignedPardon("fugitive");
        president.executeForm(unsignedPardon); // Should fail (unsigned)

        // Test executing with too low grade
        std::cout << "\n=== Testing Execution with Too Low Grade ===" << std::endl;
        intern.executeForm(pardon);    // Should fail (grade too low)

    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
