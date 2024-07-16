/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniunset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:10:18 by mman              #+#    #+#             */
/*   Updated: 2024/06/01 17:10:19 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**whileloop_del_var(char **arr, char **rtn, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arr[i] != NULL)
	{
		if (ft_strncmp(arr[i], str, ft_strlen(str)) != 0
			|| (arr[i][ft_strlen(str)] != '='
			&& arr[i][ft_strlen(str)] != '\0'))
		{
			rtn[j] = ft_strdup(arr[i]);
			if (rtn[j] == NULL)
			{
				free_arr(rtn);
				return (NULL);
			}
			j++;
		}
		i++;
	}
	rtn[j] = NULL;
	return (rtn);
}

char	**del_var(char **arr, char *str)
{
	char	**rtn;
	size_t	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	rtn = ft_calloc(sizeof(char *), i);
	if (!rtn)
		return (NULL);
	return (whileloop_del_var(arr, rtn, str));
}

int	check_unset_identifier(t_simple_cmds *simple_cmd)
{
	int	i;

	i = 0;
	while (simple_cmd->str[1][i])
	{
		if (simple_cmd->str[1][i] == '/')
		{
			ft_putstr_fd("minishell: unset: `", STDERR_FILENO);
			ft_putstr_fd(simple_cmd->str[1], STDERR_FILENO);
			ft_putendl_fd("': not a valid identifier", STDERR_FILENO);
			return (EXIT_FAILURE);
		}
		i++;
	}
	if (equal_sign(simple_cmd->str[1]) != 0)
	{
		ft_putendl_fd("unset: not a valid identifier", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	unset_error(t_simple_cmds *simple_cmd)
{
	if (!simple_cmd->str[1])
	{
		ft_putendl_fd("minishell: unset: not enough arguments", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (check_unset_identifier(simple_cmd) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	mini_unset(t_tools *tools, t_simple_cmds *simple_cmd)
{
	char	**tmp;

	if (unset_error(simple_cmd) == 1)
		return (EXIT_FAILURE);
	tmp = del_var(tools->envp, simple_cmd->str[1]);
	if (tmp)
	{
		free_arr(tools->envp);
		tools->envp = tmp;
	}
	return (EXIT_SUCCESS);
}
