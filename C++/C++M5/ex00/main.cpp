#include "Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat b1("John", 1);
        std::cout << b1 << std::endl;

        // Test promotion (should throw exception)
        try {
            b1.promoteBureaucrat();
        } catch (const std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

        Bureaucrat b2("Jane", 150);
        std::cout << b2 << std::endl;

        // Test demotion (should throw exception)
        try {
            b2.demoteBureaucrat();
        } catch (const std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

        Bureaucrat b3("Bob", 75);
        std::cout << b3 << std::endl;
        b3.promoteBureaucrat();
        std::cout << b3 << std::endl;
        b3.demoteBureaucrat();
        std::cout << b3 << std::endl;

    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
