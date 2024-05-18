#include "ScalarConverter.hpp"

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		ScalarConverter	obj;
		obj.Scalar(argv[1]);
	}
	else
	{
		std::cout << "Too maay arguments" << std::endl;
	}
	return (0);
}

