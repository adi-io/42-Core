#include "iter.hpp"

void	print(std::string const &str)
{
	std::cout << str << std::endl;
}

int	main(void)
{
	std::string str[] = { "A", "B", "C"};
	::iter(str, 3, print);
	return (0);
}
