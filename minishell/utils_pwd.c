#include "minishell.h"

int	find_pwd(t_tools *tools)
{
	int	i;

	i = 0
	while (envp[i])
	{
		if (!strncmp(envp[i], "PWD=", 4))
			tools -> pwd = strnstr(envp[i], 4, strlen(envp[i]) - 4);
		if (!strncmp(envp[i], "OLDPWD=", 7))
			tools -> old_pwd = strnstr(envp[i], 4, strlen(envp[i]) - 4);
		i++;
	}
	return (0);
}
