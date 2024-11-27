#include <iostream>
#include <vector>
#include <algorithm>


template <typename T>
typename T::iterator easyfind(T& container, int needle)
{
    typename T::iterator it = std::find(container.begin(), container.end(), needle);
    if (it == container.end())
        throw std::runtime_error("Value not found in container");
    return it;
}
