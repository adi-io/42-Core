/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 11:22:08 by mman              #+#    #+#             */
/*   Updated: 2024/04/28 19:10:28 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_global	g_global;

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

//
void	execute_command(t_simple_cmds *cmd, t_tools *tools)
{
	int	exit_code;

	exit_code = 0;
	if (cmd->redirections)
		if (check_redirections(cmd))
			exit (EXIT_FAILURE);
	if (cmd->builtin != NULL)
	{
		exit_code = cmd->builtin(tools, cmd);
		exit (exit_code);
	}
	else if (cmd->str[0][0] != '\0')
		exit_code = fetch_func(cmd, tools);
	exit (exit_code);
}
int	cmd_not_found(char *str)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd(": command not found\n", STDERR_FILENO);
	return (127);
}

// real deal
// find (program) command, excecute it
// use execve
// fetch through pathnames
int	fetch_func(t_simple_cmds *cmd, t_tools *tools)
{
	int		i;
	char	*mycmd;

	i = 0;
	cmd->str = resplit_str(cmd->str);
	if (!access(cmd->str[0], F_OK))
	{
		printf("******************** TEST PROBE ********************\n");
		printf("%s\n", cmd->str[0]);
		execve(cmd->str[0], cmd->str, tools->envp);
	}
	while (tools->paths[i])
	{
		mycmd = ft_strjoin(tools->paths[i], cmd->str[0]);
		// printf("%s -- cmd->str:%s\n", mycmd, cmd->str[4]);
		if (!access(mycmd, F_OK))
			{
				execve(mycmd, cmd->str, tools->envp);
			}
		free(mycmd);
		i++;
	}
	return (cmd_not_found(cmd->str[0]));
}

int	check_redirections(t_simple_cmds *cmd)
{
	if (cmd)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
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
		execute_command(tools->simple_cmds, tools);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		g_global.error_num = WEXITSTATUS(status);
	return (EXIT_SUCCESS);
}
//take in the CMD list and expands special cases such as "", '', or $
t_simple_cmds	*expand_argument_call(t_tools *tools, t_simple_cmds *cmd)
{
	if (tools)
		return (cmd);
	return(cmd);
}
