#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter initialized" << std::endl;
}

std::string	helperfunc(std::string str, std::string toChar)
{
	if (str == "-inff" || str == "+inff" || str == "nanf" || str == "-inf"
			|| str == "+inf" || str == "nan")
		return (toChar = "imposible");
	else
		return (toChar = "");
}

void	ScalarConverter::Scalar(std::string str)
{
	int	toInt;
	float	toFloat;
	double	toDouble;
	long	checkint;
	std::string	toChar = "";

	toInt = 0;
	toFloat = 0;
	toDouble = 0;
	toChar = helperfunc(str, toChar);
	if (str.size() == 1 && !std::isdigit(str[0]))
	{
		if (!(std::isprint(str[0])))
			std::cout << "char: : Non displayable" << std::endl;
		else
			std::cout << "char: " << str[0] << std::endl;
		std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(str[0]) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(str[0]) << ".0" << std::endl;
		return ;
	}
	checkint = std::stol(str);
	if (checkint >= INT_MAX)
	{
		std::cout << "Number too big" << std::endl;
		return ;
	}
	toInt = std::atoi(str.c_str());
	if (str[str.size() - 1] == 'f')
	{
		toFloat = std::atof(str.c_str());
		toDouble = static_cast<double>(toFloat);
	}
	else
	{
		toDouble = std::atof(str.c_str());
		toFloat = static_cast<float>(toDouble);
	}
	if (toChar == "" && std::isprint(toInt))
	{
		toChar = "'";
		toChar += static_cast<char>(toInt);
		toChar += "'";
	}
	else if (toChar == "")
	{
		toChar = "Non displayable";
	}
	std::cout << "char: " << toChar << std::endl;
	if (toChar == "imposible")
	{
		std::cout << "int: imposible" << std::endl;
	}
	else
	{
		std::cout << "int: " << toInt << std::endl;
	}

	if (toChar == "imposible" && toFloat == 0)
	{
		std::cout << "float: imposible" << std::endl;
		std::cout << "double: imposible" << std::endl;
	}
	else
	{
		if (toChar != "imposible" && toFloat - static_cast<int>(toFloat) == 0)
		{
			std::cout << "float: " << toFloat << ".0f" << std::endl;
			std::cout << "double: " << toDouble << ".0" << std::endl;
		}
		else
		{
			std::cout << "float: " << toFloat << "f" << std::endl;
			std::cout << "double: " << toDouble << std::endl;
		}
	}
}
