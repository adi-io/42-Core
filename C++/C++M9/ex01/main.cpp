#include "RPN.hpp"

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		std::string	str;
		str = argv[1];
		RPN	obj(str);
	}
	else
		std::cout << "Invalid input" << std::endl;
	return (0);
}

