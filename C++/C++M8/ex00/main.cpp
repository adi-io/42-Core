#include "easyfind.hpp"
#include <iostream>

int	main()
{
	std::vector<int> obj = {5, 4, 3, 2, 1};
	int	needle = 4;
	std::vector<int>::iterator it;

	it = easyfind(obj, 2);
	if (it != obj.end())
		std::cout << "The object was found at: " << *it << std::endl;
	else
		std::cout << "Object not found." << std::endl;
	return (0);
}
