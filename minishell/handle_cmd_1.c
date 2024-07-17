#include "minishell.h"

static int	is_parent_builtin(void *builtin)
{
	return (builtin == (void *)mini_cd
		|| builtin == (void *)mini_exit
		|| builtin == (void *)mini_pwd
		|| builtin == (void *)mini_export
		|| builtin == (void *)mini_unset);
}

static void	execute_child_process(t_simple_cmds *cmd, t_tools *tools)
{
	int	pid;

	send_heredoc(tools, cmd);
	pid = fork();
	if (pid < 0)
		ft_error(5, tools);
	if (pid == 0)
		handle_cmd(cmd, tools);
	waitpid(pid, &g_global.error_num, 0);
	if (WIFEXITED(g_global.error_num))
		g_global.error_num = WEXITSTATUS(g_global.error_num);
}

void	single_cmd(t_simple_cmds *cmd, t_tools *tools)
{
	if (!cmd || !tools)
	{
		ft_putstr_fd("Error: Null pointer in single_cmd\n", STDERR_FILENO);
		return ;
	}
	tools->simple_cmds = call_expander(tools, tools->simple_cmds);
	if (!tools->simple_cmds)
	{
		ft_putstr_fd("Error: Expansion failed in single_cmd\n", STDERR_FILENO);
		return ;
	}
	if (is_parent_builtin(cmd->builtin))
		g_global.error_num = cmd->builtin(tools, cmd);
	else
		execute_child_process(cmd, tools);
}
