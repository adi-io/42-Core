#include "minishell.h"

static int	match_env_var(char *str, char *env, int j)
{
	return (ft_strncmp(str + j + 1, env, equal_sign(env) - 1) == 0
		&& after_dol_lenght(str, j) - j == (int)equal_sign(env));
}

static void	append_env_value(char **tmp, char *env_value)
{
	char	*tmp2;
	char	*tmp3;

	tmp2 = ft_strdup(env_value);
	tmp3 = ft_strjoin(*tmp, tmp2);
	free(*tmp);
	*tmp = tmp3;
	free(tmp2);
}

int	loop_if_dollar_sign(t_tools *tools, char *str, char **tmp, int j)
{
	int		k;
	int		ret;
	char	*env_value;

	k = 0;
	ret = 0;
	while (tools->envp[k])
	{
		if (match_env_var(str, tools->envp[k], j))
		{
			env_value = tools->envp[k] + equal_sign(tools->envp[k]);
			append_env_value(tmp, env_value);
			ret = equal_sign(tools->envp[k]);
			break ;
		}
		k++;
	}
	if (ret == 0)
		ret = after_dol_lenght(str, j) - j;
	return (ret);
}
