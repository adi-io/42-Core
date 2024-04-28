#include <iostream>
#include <string>

class	ClapTrap
{
	private:
		std::string	Name;
		int	HitPoints;
		int	EnergyPoints;
		int	AttackDamage;
	public:
		ClapTrap(std::string name);
		~ClapTrap();
		void	attack(const std::string& taget);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

class	ScavTrap: private ClapTrap, public ClapTrap
{
	public:
		ScavTrap(std::sting name);
		void	guardGate();
};
