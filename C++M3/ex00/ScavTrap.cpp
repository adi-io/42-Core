#include "ClapTrap.hpp"

ScavTrap::ScavTrap(std::string name): Name(name), HitPoints(100), EnergyPoints(50), AttackDamage(20)
{
	std::cout << "Default constructer called" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "Man standing, ScavTrap" << std::endl;
}
