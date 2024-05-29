#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T& container, int needle)
{
	typename T::iterator i = std::find(container.begin(), container.end(), needle);
	return (i);
}

