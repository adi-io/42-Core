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
		void	setHitPoints(int i);
		void	setEnergyPoints(int i);
		void	setAttackDamage(int i);
		void	attack(const std::string& taget);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

