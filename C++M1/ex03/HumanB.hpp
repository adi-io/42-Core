#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"
#include "HumanA.hpp"

using namespace std;

class	HumanB
{
	private:
		Weapon* weapon;
	public:
		string	name;
		HumanB (const std::string& name);
		void	setWeapon(Weapon& weapon);
		void	attack() const;

};

#endif
