#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>

class ScalarConverter {
private:
    ScalarConverter();
    ~ScalarConverter();

    ScalarConverter(const ScalarConverter&);
    ScalarConverter& operator=(const ScalarConverter&);

public:
    static void convert(const std::string& literal);
};
