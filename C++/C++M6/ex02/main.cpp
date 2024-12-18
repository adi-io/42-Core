#include "Class.hpp"

Base::~Base() {};

Base* generate(void)
{
    std::srand(time(NULL));

    int n = rand() % 3;
    switch (n)
    {
        case 0:
            std::cout << "generated A class" << std::endl;
            return (new A);
        case 1:
            std::cout << "generated B class" << std::endl;
            return (new B);
        case 2:
            std::cout << "generated C class" << std::endl;
            return (new C);
    }
    std::cout << "Unknown error occurred" << std::endl;
    return (NULL);
}

void	identify(Base* p)
{
	if (dynamic_cast<A*> (p) != NULL)
		std::cout << "A class has been identified" << std::endl;
	else if (dynamic_cast<B*> (p) != NULL)
		std::cout << "B class has been identified" << std::endl;
	else if (dynamic_cast<C*> (p) != NULL)
		std::cout << "C class has been identified" << std::endl;
	else
		std::cout <<"Out of bound class error" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		A& aux = dynamic_cast<A&> (p);
		(void)aux;
		std::cout << "A class was identified" << std::endl;
		return ;
	}
	catch (...) {}
	try
	{
		B& aux = dynamic_cast<B&> (p);
		(void)aux;
		std::cout << "B class was identified" << std::endl;
		return ;
	}
	catch (...) {}
	try
	{
		C& aux = dynamic_cast<C&> (p);
		(void)aux;
		std::cout << "C class was identified" << std::endl;
		return ;
	}
	catch (...) {}
	std::cout <<"Out of bound class error" << std::endl;
}

int	main(void)
{
	Base*	base;

	base = generate();
	identify(base);
	identify(*base);
	delete base;
	return (0);
}
