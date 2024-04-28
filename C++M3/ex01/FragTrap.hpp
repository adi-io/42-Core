#include <iostream>
#include <string>

#include "ClapTrap.hpp"

class	FragTrap: public ClapTrap
{
	public:
		FragTrap(std::string name);
		~FragTrap();
		void	guardGate();
		attack(const std::string& target)
};
