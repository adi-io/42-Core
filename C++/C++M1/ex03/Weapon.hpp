#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

using namespace std;

class	Weapon
{
	private:
		string type;

	public:
		Weapon(const std::string& type);
		const string&	getType(void) const;
		void	setType(const string& ntype);
};

#endif
