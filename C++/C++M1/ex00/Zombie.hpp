#include <iostream>
#include <string>

using namespace std;

class	Zombie
{
	private:
		string	Name;

	public:
		~Zombie ()
		{
			std::cout << Name << " Destroyed" << endl;
		}
		void	SetName(std::string name)
		{
			Name = name;
		}
		void	announce(void)
		{
			std::cout << Name << ": BraiiiiiiinnnzzzZ..." << endl;
		}
};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );
