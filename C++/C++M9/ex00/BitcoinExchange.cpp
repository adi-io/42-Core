#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <climits>
#include "BitcoinExchange.hpp"

BTC::BTC() {};

BTC::~BTC() {};

void	BTC::parser()
{
	std::ifstream file("cleaned_data.csv");
	if (!file.is_open())
	{
		std::cout << "Database file missing" << std::endl;
		return ;
	}
	std::string line;
	while (std::getline(file, line))
	{
		std::istringstream ss(line);
		std::string date;
		std::string exchangeRatestr;
		if (std::getline(ss, date, ',') && std::getline(ss, exchangeRatestr))
		{
			try
			{
				float i = std::stof(exchangeRatestr);
				exchangeRates[date] = i;
			}
			catch (const std::exception& e)
			{
				std::cerr << "Invalid exchange rate for date: " << date << std::endl;
				continue;
			}
		}
	}
	file.close();
}

bool isValidDate(const std::string& date) {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int year, month, day;
    try {
        year = std::stoi(date.substr(0, 4));
        month = std::stoi(date.substr(5, 2));
        day = std::stoi(date.substr(8, 2));
    } catch (...) {
        return false;
    }

    if (year < 1900 || year > 2023 ||
        month < 1 || month > 12 ||
        day < 1 || day > 31)
        return false;

    return true;
}

void BTC::parser2() {
    std::ifstream file("input.txt");
    if (!file.is_open()) {
        std::cout << "Error: could not open file." << std::endl;
        return;
    }
    if (file.peek() == std::ifstream::traits_type::eof()) {
        std::cout << "Error: empty file" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        size_t delim = line.find('|');
        if (delim == std::string::npos) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, delim);
        std::string value = line.substr(delim + 1);

        date.erase(date.find_last_not_of(" \n\r\t")+1);
        value.erase(0, value.find_first_not_of(" \n\r\t"));

        if (!isValidDate(date)) {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }

        float fval;
        try {
            fval = std::stof(value);
            if (fval > 1000) {
                std::cout << "Error: too large a number." << std::endl;
                continue;
            }
            if (fval < 0) {
                std::cout << "Error: not a positive number." << std::endl;
                continue;
            }
        } catch (...) {
            std::cout << "Error: bad input => " << value << std::endl;
            continue;
        }

        inputData.emplace_back(date, fval);
    }
    file.close();
}

void	BTC::print()
{
	std::vector<std::pair<std::string, float>>::iterator it;

	for (it = inputData.begin(); it != inputData.end(); ++it)
	{
		if (it -> second == -42.42f)
			std::cout << "Error: bad input => " << it -> first << std::endl;
		else if (it -> second == -41.41f)
			std::cout << "Error: too large a number." << std::endl;
		else if (it -> second < 0)
			std::cout << "Error: not a positive number."<< std::endl;
		else
		{
			std::cout << it -> first << " => " << it -> second << " = " <<
				exchangeRates[it -> first] * it -> second << std::endl;
		}
	}
}

int	main()
{
	BTC	obj;

	obj.parser();
	obj.parser2();
	obj.print();
	return (0);
}
