#include "Zombie.hpp"

int	main(void)
{
	Zombie	*Zombie_Heap;

	Zombie_Heap = zombieHorde(5, "MZ");
	std::cout << endl;
	delete[] Zombie_Heap;
	return (0);
}
