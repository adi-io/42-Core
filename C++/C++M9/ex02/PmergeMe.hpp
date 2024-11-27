#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <cmath>

class PmergeMe {
private:
    std::vector<int> vec;
    std::deque<int> deq;

    // Helper functions for Ford-Johnson algorithm
    template<typename T>
    void fordJohnsonSort(T& container);

    template<typename T>
    void insertElement(T& container, size_t start, size_t end, typename T::value_type value);

    std::vector<size_t> generateJacobsthalNumbers(size_t n);

public:
    PmergeMe(int argc, char** argv);
    ~PmergeMe() {}

    void execute();
    void displayResults(double vecTime, double deqTime);
    bool validateInput(const std::string& input);
};
