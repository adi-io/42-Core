#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name )
{
	int	i;
	Zombie*	ManyZombies = new Zombie[N];

	i = 0;
	while (i < N)
	{
		ManyZombies[i].SetName(name);
		i++;
	}
	i = 0;
	while (i < N)
	{
		ManyZombies[i].announce();
		i++;
	}
	return (ManyZombies);
}
