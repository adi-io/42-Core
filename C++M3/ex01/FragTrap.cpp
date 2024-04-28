#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
	std::cout << "FragTrap constructer called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructer called" << std::endl;
}

void	guardGate()
{
	std::cout << this->Name << " is guading the gate" << std:endl;
}

void	FragTrap::attack(const std::string& target)
{
	takeDamage(1);
	std::cout << "FragTrap " << this->Name << " attacks " << target << " causing 1 points of damage!" << std::endl;
}
