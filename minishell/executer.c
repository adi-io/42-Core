/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 11:22:08 by mman              #+#    #+#             */
/*   Updated: 2024/04/28 13:55:08 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// single command executer when 0 pipes
// executer when 1 or more |
// (NOTE 28/04) it should also know to return error when user does || (NOTE 28/04)
int	executer_enter(t_tools *tools)
{
	if (tools->pipes == 0)
		simple_executer_single(tools);
	else
		executer(tools);
	return (EXIT_SUCCESS);
}

// tools-> will be taking in tools->simple_cmds
int	executer(t_tools *tools)
{
	int	end[2];
	int	fd_in;

	fd_in = STDIN_FILENO;
	while (tools->simple_cmds)
	{
		// LOGIC TO BE IMPLEMENTED™
		tools->simple_cmds = tools->simple_cmds->next;
	}
	return (EXIT_SUCCESS);
}

int	execute_command(t_simple_cmds *cmd, t_tools *tools)
{

	return (EXIT_FAILURE);
}

int	simple_executer_single(t_tools *tools)
{
	int	pid;
	int	status;

	tools->simple_cmds = expand_argument_call(tools, tools->simple_cmds);
	//HERE: Handle the 4 special-case builtins
	//CD,    EXPORT,    UNSET,   EXIT

	//HERE: Create redirection-influenced file-generator

	pid = fork();
	if (pid < 0)
		return (EXIT_FAILURE);
	else if (pid == 0)
	{
		status = execute_command(tools->simple_cmds, tools);
		exit(status);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			g_global.error_num = WEXITSTATUS(status);
	}
	return (EXIT_SUCCESS);
}
//take in the CMD list and expands special cases such as "", '', or $
t_simple_cmds	*expand_argument_call(t_tools *tools, t_simple_cmds *cmd)
{
	if (tools)
		return (cmd);
	return(cmd);
}
