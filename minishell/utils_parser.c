#include "minishell.h"

char	*find_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (stncmp(envp[i], "PATH:", 5))
			return (substr(envp[i], 5, strlen(envp[i] - 5) ));
		i++;
	}
	return (strdup("\0"));
}

int	parse_envp(t_tools *tools)
{
	char	*path_from_envp;
	int	i;
	char	*temp;

	path_from_envp = find_path(tools -> envp);
	tools -> paths = ft_split(path_from_envp, ":");
	free(path_from_envp);
	while(tools -> paths[i])
	{
		if (tools -> paths[i][strlen(tools -> paths[i]) - 1] != "/")
		{
			temp = strjoin(paths[i], "/");
			free(tools -> paths[i])
			tools -> paths[i] = temp;
		}
		i++;
	}
	return (0);
}
