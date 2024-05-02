#include <iostream>
#include <string>

#include "ClapTrap.hpp"

class	FragTrap: public ClapTrap
{
	public:
		FragTrap(std::string name);
		~FragTrap();
		void	highFivesGuys(void);
		void	attack(const std::string& target);
};
