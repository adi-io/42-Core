#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

using namespace std;

class	HumanA
{
	private:
		Weapon& weapon;
	public:
		string	name;

		HumanA (const std::string& str, Weapon& weapon);
		void	attack() const;
};

#endif
