#include "minishell.h"

char	*ft_strdup1(const char *s1)
{
	char	*s2;
	size_t	size;
	size_t	i;

	i = 0;
	size = strlen(s1);
	s2 = (char *)malloc((size * sizeof(char)) + 1);
	if (!s2)
		return (0);
	while (i < size)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

void	add_path_to_env(t_tools *tools)
{
	int	i;
	char	*tmp;

	i = 0;
	while (tools->envp[i])
	{
		if (ft_strncmp(tools->envp[i], "PWD=", 4) == 0)
		{
			tmp = ft_strjoin("PWD=", tools->pwd);
			free(tools->envp[i]);
			tools->envp[i] = tmp;
		}
		else if (ft_strncmp(tools->envp[i], "OLDPWD=", 7) == 0)
		{
			tmp = ft_strjoin("OLDPWD=", tools->pwd);
			free(tools->envp[i]);
			tools->envp[i] = tmp;
		}
		i++;
	}
}

char	*find_path_minicd(char *str, t_tools *tools)
{
	int	i;

	i = 0;
	while(tools->envp[i])
	{
		if (ft_strncmp(tools->envp[i], str, strlen(str)) == 0)
			return (ft_substr(tools->envp[i], strlen(str),
						strlen(tools->envp[i]) - strlen(str)));
		i++;
	}
	return (NULL);
}

int	goto_path(t_tools *tools, char *str)
{
	char	*tmp;
	int	res;

	tmp = find_path_minicd(str, tools);
	res = chdir(tmp);
	free(tmp);
	//error handling
}

void	change_path(t_tools *tools)
{
	char	*tmp;

	tmp = ft_strdup1(tools->pwd);
	free(tools->old_pwd);
	tools->old_pwd = tmp;
	free(tools->pwd);
	tools->pwd = getcwd(NULL, sizeof(NULL));
}

int	mini_cd(t_tools *tools, t_simple_cmds *simple_cmd)
{
	int	res;

	printf(" -- I am called (says mini_cd)");
	tools->pwd = ft_strdup(getenv("PWD"));
	tools->old_pwd = ft_strdup(getenv("PWD"));
	printf(" -- pwd before cd: %s -- ", tools->pwd);
	if (!simple_cmd -> str[1])
		res = goto_path(tools, "HOME=");
	else if (ft_strncmp(simple_cmd->str[1], "-", 1) == 0)
		res = goto_path(tools, "OLDPWD=");
	else
	{
		res = chdir(simple_cmd->str[1]);
	}
	if (res != 0)
		return (EXIT_FAILURE);
	// printf("res: %d\n", res);
//	change_path(tools);
//	add_path_to_env(tools);
	printf(" -- EXIT SUCCESS (minicd) --");
	return(EXIT_SUCCESS);
}
