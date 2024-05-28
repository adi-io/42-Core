#include "Array.hpp"
#include <iostream>

int	main(void)
{
	int	i;
	Array<int>	intArray0;
	Array<int>	intArray(5);

	i = 0;
	while (i < 5)
	{
		intArray[i] = i;
		i++;
	};
	intArray0 = intArray;
	std::cout << intArray0[1] << std::endl;
	Array<int>	temp = intArray0;
	std::cout << intArray0[2] << std::endl;
	try
	{
		intArray0[-2] = 0;
	}

	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
