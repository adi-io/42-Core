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
		~ClapTrap(void);
		void	attack(const std::string& taget);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

class	ScavTrap: public ClapTrap
{
	public:
		ScavTrap(std::string name);
		void	guardGate(void);
};
