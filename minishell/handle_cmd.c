/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:09:43 by mman              #+#    #+#             */
/*   Updated: 2024/07/12 21:31:17 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	executer_enter(t_tools *tools)
{
	if (tools->pipes == 0)
	{
		single_cmd(tools->simple_cmds, tools);
	}
	else
	{
		tools -> pid = ft_calloc(sizeof(int ), tools -> pipes + 2);
		if (!tools -> pid)
			return (ft_error(1, tools));
		executor(tools);
	}
	g_global.in_cmd = 0;
	return (EXIT_SUCCESS);
}

static void	execute_cmd(char *cmd_path, char **cmd_str, char **envp)
{
	execve(cmd_path, cmd_str, envp);
	perror("execve");
	exit(EXIT_FAILURE);
}

int	find_cmd(t_simple_cmds *cmd, t_tools *tools)
{
	int		i;
	char	*mycmd;

	i = 0;
	cmd->str = resplit_str(cmd->str);
	if (!access(cmd->str[0], F_OK))
		execute_cmd(cmd->str[0], cmd->str, tools->envp);
	while (tools->paths[i])
	{
		mycmd = ft_strjoin(tools->paths[i], cmd->str[0]);
		if (!access(mycmd, F_OK))
		{
			execute_cmd(mycmd, cmd->str, tools->envp);
			free(mycmd);
		}
		free(mycmd);
		i++;
	}
	return (cmd_not_found(cmd->str[0]));
}

void	dup_cmd(t_simple_cmds *cmd, t_tools *tools, int end[2], int fd_in)
{
	if (cmd->prev && dup2(fd_in, STDIN_FILENO) < 0)
		ft_error(4, tools);
	close(end[0]);
	if (cmd->next && dup2(end[1], STDOUT_FILENO) < 0)
		ft_error(4, tools);
	close(end[1]);
	if (cmd->prev)
		close(fd_in);
	handle_cmd(cmd, tools);
}
