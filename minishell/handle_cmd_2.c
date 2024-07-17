#include "minishell.h"

static void	handle_builtin(t_simple_cmds *cmd, t_tools *tools)
{
	int	exit_code;

	exit_code = cmd->builtin(tools, cmd);
	exit(exit_code);
}

static void	handle_external_cmd(t_simple_cmds *cmd, t_tools *tools)
{
	int	exit_code;

	if (cmd->str && cmd->str[0] && cmd->str[0][0] != '\0')
		exit_code = find_cmd(cmd, tools);
	else
	{
		ft_putstr_fd("\n", STDERR_FILENO);
		exit(1);
	}
	exit(exit_code);
}

void	handle_cmd(t_simple_cmds *cmd, t_tools *tools)
{
	if (!cmd || !tools)
	{
		ft_putstr_fd("Error: Null pointer in handle_cmd\n", STDERR_FILENO);
		exit(1);
	}
	if (cmd->redirections && check_redirections(cmd))
		exit(1);
	if (cmd->builtin != NULL)
		handle_builtin(cmd, tools);
	else
		handle_external_cmd(cmd, tools);
}
