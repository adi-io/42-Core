#include "minishell.h"

char	*find_path_minicd(char *str, t_tools *tools)
{
	int	i;

	i = 0;
	while (tools -> envp[i])
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
	int		res;

	tmp = find_path_minicd(str, tools);
	res = chdir(tmp);
	free(tmp);
}

int	handle_cd_path(t_tools *tools, t_simple_cmds *simple_cmd)
{
	int	res;

	if (!simple_cmd->str[1])
		res = goto_path(tools, "HOME=");
	else if (ft_strncmp(simple_cmd->str[1], "-", 1) == 0)
	{
		res = goto_path(tools, "OLDPWD=");
		printf("\n%s\n", tools->old_pwd);
	}
	else
		res = chdir(simple_cmd->str[1]);
	return (res);
}

int	update_pwd(t_tools *tools)
{
	char	*new_pwd;

	free(tools->old_pwd);
	tools->old_pwd = tools->pwd;
	new_pwd = getcwd(NULL, 0);
	if (!new_pwd)
	{
		perror("getcwd");
		return (EXIT_FAILURE);
	}
	tools->pwd = new_pwd;
	return (EXIT_SUCCESS);
}

int	mini_cd(t_tools *tools, t_simple_cmds *simple_cmd)
{
	int	res;

	res = handle_cd_path(tools, simple_cmd);
	if (res != 0)
		return (EXIT_FAILURE);
	return (update_pwd(tools));
}
