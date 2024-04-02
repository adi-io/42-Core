#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_tools	tools;

	if (argc != 1 || argv[1])
	{
		printf("This program does not accept arguments);
		return (1);
	}
	tools.envp = ft_memmory(envp);
	find_pwd(&tools);
	init_tools(&tools);
	printf("Welcome Bros");
	minishell_loop(&tools);
	return (0);
}
