#include "iter.hpp"

template<typename T>
void print(T const &x)
{
    std::cout << x << std::endl;
}

void multiply_by_two(int const &n)
{
    std::cout << n * 2 << std::endl;
}

int main(void)
{
    // Test with strings
    std::string str[] = {"Hello", "World", "!"};
    std::cout << "Testing with strings:" << std::endl;
    iter(str, 3, print);

    // Test with integers
    int numbers[] = {1, 2, 3, 4, 5};
    std::cout << "\nTesting with integers:" << std::endl;
    iter(numbers, 5, print);

    // Test with different function
    std::cout << "\nTesting with multiply_by_two function:" << std::endl;
    iter(numbers, 5, multiply_by_two);

    // Test with doubles
    double doubles[] = {1.1, 2.2, 3.3};
    std::cout << "\nTesting with doubles:" << std::endl;
    iter(doubles, 3, print);

    return (0);
}
