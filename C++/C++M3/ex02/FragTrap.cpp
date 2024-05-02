#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
	std::cout << "FragTrap constructer called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructer called" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << this->getName() << " says hello y'all" << std::endl;
}

/*void	FragTrap::attack(const std::string& target)
{
	takeDamage(1);
	std::cout << "FragTrap " << Name << " attacks " << target << " causing 1 points of damage!" << std::endl;
}*/
