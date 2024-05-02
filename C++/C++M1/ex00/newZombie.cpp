#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
	Zombie*	NewZ = new Zombie;

	NewZ -> SetName(name);
	return (NewZ);
}
