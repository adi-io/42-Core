#include <iostream>
#include <string>

using namespace std;

int	main(void)
{
	string	str;
	string	*stringPTR;
	string	&stringREF = str;

	str = "HI THIS IS BRAIN";
	stringPTR = &str;
	std::cout << "Mamory address of the string variable: " << &str << endl;
	std::cout << "Mamory address of the string pointer: " << &stringPTR << endl;
	std::cout << "Mamory address of the ref variable: " << &stringREF << endl;

	std::cout << "The value of the string variable: " << str << endl;
	std::cout << "The value pointed by the string pointer: " << *stringPTR << endl;
	std::cout << "The value pointed by the ref variable: " << stringREF << endl;


	return (0);
}
