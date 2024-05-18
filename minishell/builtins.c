#include "minishell.h"

int	(*builtin_arr(char *str))(t_tools *tools, t_simple_cmds *simple_cmd)
{
	static void	*builtins[1][2] = {
	//{"echo", mini_echo},
	{"cd", mini_cd},
	//{"pwd", mini_pwd},
	//{"export", mini_export},
	//{"unset", mini_unset},
	//{"env", mini_env},
	//{"exit", mini_exit}
	};
	int			i;

	i = 0;
	while (i < 1)
	{
		if (str)
		{
			if (!ft_strncmp(builtins[i][0], str, ft_strlen((builtins[i][0]))))
				return (builtins[i][1]);
		}
		i++;
	}
	return (NULL);
}
