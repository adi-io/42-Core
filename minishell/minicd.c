/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minicd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:09:50 by mman              #+#    #+#             */
/*   Updated: 2024/06/01 17:09:51 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_path_to_env(t_tools *tools)
{
	int		i;
	char	*tmp;

	i = 0;
	while (tools->envp[i])
	{
		if (ft_strncmp(tools->envp[i], "PWD=", 4) == 0)
		{
			tmp = ft_strjoin("PWD=", tools->pwd);
			free(tools->envp[i]);
			tools->envp[i] = tmp;
		}
		else if (ft_strncmp(tools->envp[i], "OLDPWD=", 7) == 0)
		{
			tmp = ft_strjoin("OLDPWD=", tools->pwd);
			free(tools->envp[i]);
			tools->envp[i] = tmp;
		}
		i++;
	}
}

void	change_path(t_tools *tools)
{
	char	*tmp;

	tmp = ft_strdup(tools->pwd);
	free(tools->old_pwd);
	tools->old_pwd = tmp;
	free(tools->pwd);
	tools->pwd = getcwd(NULL, sizeof(NULL));
}

/*int	mini_cd(t_tools *tools, t_simple_cmds *simple_cmd)
{
	int		res;
	char	*new_pwd;

	if (!simple_cmd -> str[1])
		res = goto_path(tools, "HOME=");
	else if (ft_strncmp(simple_cmd->str[1], "-", 1) == 0)
	{
		res = goto_path(tools, "OLDPWD=");
		printf("\n%s\n", tools->old_pwd);
	}
	else
		res = chdir(simple_cmd->str[1]);
	if (res != 0)
		return (EXIT_FAILURE);
	else
	{
		free(tools->old_pwd);
		tools -> old_pwd = tools -> pwd;
		new_pwd = getcwd(NULL, 0);
		if (!new_pwd)
		{
			perror("getcwd");
			return (EXIT_FAILURE);
		}
		tools->pwd = new_pwd;
	}
	return (EXIT_SUCCESS);
}*/
