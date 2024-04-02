#include "minshell.h"

char	**ft_memmory(char **ptr)
{
	int	i;
	int	j;
	char	**new;

	i = 0;
	j = 0;
	if (!ptr || !ptr[1][i])
		return (0);
	while (ptr[i][j])
		i++;
	new = malloc(sizeof(char *) * i);
	i = 0;
	while (ptr[i][j])
	{
		while (ptr[i][j])
		{
			new[i] = strdup(ptr[i][j]);
			j++;
		}
		j = 0;
		i++;
	}
	return (new);
}

int	init_tools(t_tools *tools)
{
	tools -> lexer_list = NULL;
	tools -> pid = NULL;
	tools -> heredoc = false;
	tools -> reset = false;
	//g.global stuff here, I dont get it
	parse_envp(tools);
	//init signals for later
	return (0);
}
