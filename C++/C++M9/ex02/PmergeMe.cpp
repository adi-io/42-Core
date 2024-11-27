#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char** argv) {
    for (int i = 1; i < argc; ++i) {
        if (!validateInput(argv[i])) {
            throw std::invalid_argument("Invalid input: " + std::string(argv[i]));
        }
        int num = std::atoi(argv[i]);
        vec.push_back(num);
        deq.push_back(num);
    }
}

bool PmergeMe::validateInput(const std::string& input) {
    if (input.empty()) return false;
    for (size_t i = 0; i < input.length(); ++i) {
        if (!std::isdigit(input[i])) return false;
    }
    return true;
}

std::vector<size_t> PmergeMe::generateJacobsthalNumbers(size_t n) {
    std::vector<size_t> jacobsthal;
    if (n == 0) return jacobsthal;

    jacobsthal.push_back(0);
    if (n == 1) return jacobsthal;

    jacobsthal.push_back(1);
    size_t i = 2;
    while (jacobsthal.back() < n) {
        size_t next = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
        if (next > n) break;
        jacobsthal.push_back(next);
        ++i;
    }
    return jacobsthal;
}

template<typename T>
void PmergeMe::insertElement(T& container, size_t start, size_t end,
                           typename T::value_type value) {
    while (start < end) {
        size_t mid = start + (end - start) / 2;
        if (container[mid] > value)
            end = mid;
        else
            start = mid + 1;
    }
    container.insert(container.begin() + start, value);
}

template<typename T>
void PmergeMe::fordJohnsonSort(T& container) {
    if (container.size() <= 1) return;

    std::vector<std::pair<typename T::value_type, typename T::value_type>> pairs;
    size_t unpaired = container.size() % 2;
    typename T::value_type unpaired_element;

    for (size_t i = 0; i < container.size() - unpaired; i += 2) {
        typename T::value_type a = container[i];
        typename T::value_type b = container[i + 1];
        if (a > b) std::swap(a, b);
        pairs.push_back(std::make_pair(a, b));
    }

    if (unpaired) {
        unpaired_element = container.back();
    }

    std::sort(pairs.begin(), pairs.end(),
              [](const auto& a, const auto& b) { return a.second < b.second; });

    container.clear();
    for (const auto& pair : pairs) {
        container.push_back(pair.second);
    }

    std::vector<typename T::value_type> pending;
    for (const auto& pair : pairs) {
        pending.push_back(pair.first);
    }
    if (unpaired) pending.push_back(unpaired_element);

    std::vector<size_t> jacobsthal = generateJacobsthalNumbers(pending.size());

    if (!pending.empty()) {
        insertElement(container, 0, container.size(), pending[0]);
    }

    for (size_t i = 1; i < jacobsthal.size(); ++i) {
        size_t start = jacobsthal[i - 1];
        size_t end = jacobsthal[i];

        for (size_t j = end; j > start; --j) {
            if (j - 1 < pending.size()) {
                insertElement(container, 0, container.size(), pending[j - 1]);
            }
        }
    }

    for (size_t i = jacobsthal.back() + 1; i <= pending.size(); ++i) {
        insertElement(container, 0, container.size(), pending[i - 1]);
    }
}

void PmergeMe::execute() {
    std::cout << "Before: ";
    for (const auto& num : vec) std::cout << num << " ";
    std::cout << std::endl;

    clock_t start = clock();
    fordJohnsonSort(vec);
    clock_t end = clock();
    double vecTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;

    start = clock();
    fordJohnsonSort(deq);
    end = clock();
    double deqTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;

    displayResults(vecTime, deqTime);
}

void PmergeMe::displayResults(double vecTime, double deqTime) {
    std::cout << "After: ";
    for (const auto& num : vec) std::cout << num << " ";
    std::cout << std::endl;

    std::cout << "Time to process a range of " << vec.size()
              << " elements with std::vector : " << std::fixed
              << std::setprecision(5) << vecTime << " ms" << std::endl;

    std::cout << "Time to process a range of " << deq.size()
              << " elements with std::deque : " << std::fixed
              << std::setprecision(5) << deqTime << " ms" << std::endl;
}
