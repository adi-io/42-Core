#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
	std::cout << "ScavTrap constructer called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructer called" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << this->getName() << " is guading the gate" << std::endl;
}

/*void	ScavTrap::attack(const std::string& target)
{
	takeDamage(1);
	std::cout << "ScavTrap " << Name << " attacks " << target << " causing 1 points of damage!" << std::endl;
}*/
