#include "MutantStack.hpp"
#include <iostream>

int	main(void)
{
	MutantStack<int> mystack;
	mystack.push(10);
	mystack.push(20);
	mystack.push(30);

	for (MutantStack<int>::iterator it = mystack.begin(); it != mystack.end(); ++it) {
		std::cout << *it << " " << std::endl;
	}
	return (0);
}
