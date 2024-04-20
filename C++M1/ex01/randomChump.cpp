#include "Zombie.hpp"

void randomChump( std::string name )
{
	Zombie	NewZ;

	NewZ.SetName(name);
	NewZ.announce();
}
