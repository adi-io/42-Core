#include "ScalarConverter.hpp"
#include <cmath>
#include <iomanip>

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}

static bool isChar(const std::string& str)
{
    return (str.length() == 1 && !std::isdigit(str[0]));
}

static bool isPseudoLiteral(const std::string& str)
{
    return (str == "-inff" || str == "+inff" || str == "nanf" ||
            str == "-inf" || str == "+inf" || str == "nan");
}

void ScalarConverter::convert(const std::string& literal)
{
    if (isChar(literal))
    {
        char c = literal[0];
        std::cout << "char: ";
        if (std::isprint(c))
            std::cout << "'" << c << "'" << std::endl;
        else
            std::cout << "Non displayable" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
        return;
    }

    if (isPseudoLiteral(literal))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        if (literal == "nanf" || literal == "nan")
        {
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
        }
        else if (literal == "+inff" || literal == "+inf")
        {
            std::cout << "float: +inff" << std::endl;
            std::cout << "double: +inf" << std::endl;
        }
        else
        {
            std::cout << "float: -inff" << std::endl;
            std::cout << "double: -inf" << std::endl;
        }
        return;
    }

    try
    {
        double d = std::atof(literal.c_str());
        int i = static_cast<int>(d);
        float f = static_cast<float>(d);

        std::cout << "char: ";
        if (i >= 32 && i <= 126)
            std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
        else
            std::cout << "Non displayable" << std::endl;

        std::cout << "int: " << i << std::endl;

        if (f - static_cast<int>(f) == 0)
            std::cout << "float: " << f << ".0f" << std::endl;
        else
            std::cout << "float: " << f << "f" << std::endl;

        if (d - static_cast<int>(d) == 0)
            std::cout << "double: " << d << ".0" << std::endl;
        else
            std::cout << "double: " << d << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: conversion failed" << std::endl;
    }
}
