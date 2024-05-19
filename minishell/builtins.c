/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 03:40:19 by mman              #+#    #+#             */
/*   Updated: 2024/05/19 03:41:37 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_execute_builtins(t_simple_cmds *cmd, t_tools *tools)
{
	if (!ft_strncmp(tools->simple_cmds->str[0], "cd", 2))
	{
		// printf("Command: %s\n", cmd->str[0]);
		g_global.error_num = mini_cd(tools, cmd);
		return (0);
	}
	else if (!ft_strncmp(tools->simple_cmds->str[0], "pwd", 2))
	{
		// printf("Command: %s\n", cmd->str[0]);
		g_global.error_num = mini_pwd(tools);
		return (0);
	}
	else if (!ft_strncmp(tools->simple_cmds->str[0], "echo", 3))
	{
		// printf("Command: %s\n", cmd->str[0]);
		g_global.error_num = mini_echo(tools, cmd);
		return (0);
	}
	else if (!ft_strncmp(tools->simple_cmds->str[0], "exit", 3))
		mini_exit(tools);
	else
		return (EXIT_FAILURE);
}