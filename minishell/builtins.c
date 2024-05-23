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
	else if (!ft_strncmp(tools->simple_cmds->str[0], "export", 3))
	{
		// printf("Command: %s\n", cmd->str[0]);
		g_global.error_num = mini_export(tools, cmd);
		return (0);
	}
	else if (!ft_strncmp(tools->simple_cmds->str[0], "env", 3))
	{
		// printf("Command: %s\n", cmd->str[0]);
		g_global.error_num = mini_env(tools, cmd);
		return (0);
	}
	else if (!ft_strncmp(tools->simple_cmds->str[0], "unset", 3))
	{
		// printf("Command: %s\n", cmd->str[0]);
		g_global.error_num = mini_unset(tools, cmd);
		return (0);
	}
	else if (!ft_strncmp(tools->simple_cmds->str[0], "exit", 3))
		mini_exit(tools);
	else
		return (EXIT_FAILURE);
}
