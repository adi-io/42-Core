#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): Name(name), HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
	std::cout << "Default constructer called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Default destructer called" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->EnergyPoints =- amount;
}

void	ClapTrap::attack(const std::string& target)
{
	takeDamage(1);
	std::cout << "ClapTrap " << this->Name << " attacks " << target << " causing 1 points of damage!" << std::endl;
}

void	ClapTrap::setHitPoints(int i)
{
	this->HitPoints = i;
}

void	ClapTrap::setEnergyPoints(int i)
{
	this->EnergyPoints = i;
}
void	ClapTrap::setAttackDamage(int i)
{
	this->AttackDamage = i;
}

std::string	ClapTrap::getName(void)
{
	return (Name);
}

