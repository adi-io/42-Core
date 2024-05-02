#include <iostream>
#include <string>

class	Harl
{
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

	public:
		void	complain(std::string level)
		{
			void	(Harl::*ptr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
			std::string levels[4] = {"debug", "info", "warning", "error"};
			int	i = 0;
			while (i < 4 && levels[i].compare(level))
				i++;
			if (i < 4)
				(this->*(ptr[i]))();
		}
};

