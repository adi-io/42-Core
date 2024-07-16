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

int	find_cmd(t_simple_cmds *cmd, t_tools *tools)
{
	int		i;
	char	*mycmd;

	i = 0;
	cmd->str = resplit_str(cmd->str);
	if (!access(cmd->str[0], F_OK))
	{
		execve(cmd->str[0], cmd->str, tools->envp);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	while (tools->paths[i])
	{
		mycmd = ft_strjoin(tools->paths[i], cmd->str[0]);
		if (!access(mycmd, F_OK))
		{
			execve(mycmd, cmd->str, tools->envp);
			free(mycmd);
			perror("execve");
			printf("what");
			exit(EXIT_FAILURE);
		}
		free(mycmd);
		i++;
	}
	return (cmd_not_found(cmd->str[0]));
}

void	handle_cmd(t_simple_cmds *cmd, t_tools *tools)
{
	int	exit_code;

	exit_code = 0;
	if (!cmd || !tools)
	{
		fprintf(stderr, "Error: Null pointer in handle_cmd\n");
		exit(1);
	}
	if (cmd->redirections)
	{
		if (check_redirections(cmd))
			exit(1);
	}
	if (cmd->builtin != NULL)
	{
		exit_code = cmd->builtin(tools, cmd);
		exit(exit_code);
	}
	else if (cmd->str && cmd->str[0] && cmd->str[0][0] != '\0')
	{
		exit_code = find_cmd(cmd, tools);
	}
	else
	{
		fprintf(stderr, "\n");
		exit(1);
	}
	exit(exit_code);
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

void	single_cmd(t_simple_cmds *cmd, t_tools *tools)
{
	int	pid;
	int	status;

	if (!cmd || !tools)
	{
		fprintf(stderr, "Error: Null pointer in single_cmd\n");
		return ;
	}
	tools -> simple_cmds = call_expander(tools, tools -> simple_cmds);
	if (!tools->simple_cmds)
	{
		fprintf(stderr, "Error: Expansion failed in single_cmd\n");
		return ;
	}
	if ((void (*)())cmd->builtin == (void (*)())mini_cd ||
			(void (*)())cmd->builtin == (void (*)())mini_exit ||
			(void (*)())cmd->builtin == (void (*)())mini_pwd ||
			(void (*)())cmd->builtin == (void (*)())mini_export ||
			(void (*)())cmd->builtin == (void (*)())mini_unset)
	{
		g_global.error_num = cmd->builtin(tools, cmd);
		return ;
	}
	send_heredoc(tools, cmd);
	pid = fork();
	if (pid < 0)
		ft_error(5, tools);
	if (pid == 0)
		handle_cmd(cmd, tools);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		g_global.error_num = WEXITSTATUS(status);
}
