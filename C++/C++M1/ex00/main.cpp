#include "Zombie.hpp"

int	main(void)
{
	Zombie	*Zombie_Heap;

	Zombie_Heap = newZombie("HeapZombie");
	randomChump("StackZombie");
	std::cout << endl;
	delete Zombie_Heap;
	return (0);
}
