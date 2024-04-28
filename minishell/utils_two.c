/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 22:31:56 by mman              #+#    #+#             */
/*   Updated: 2024/04/28 12:08:06 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	envpprint(t_tools tools)
{
	int	i;

	i = 0;
	while (tools.envp[i] != NULL)
	{
		printf("env[%d]: %s\n", i, tools.envp[i]);
		i++;
	}
}

// return the pointer back to the first node in the list
t_simple_cmds	*ft_simple_cmdsfirst(t_simple_cmds *list_of_cmds)
{
	int	i;

	i = 0;
	if (!list_of_cmds)
		return (NULL);
	while (list_of_cmds->prev != NULL)
	{
		list_of_cmds = list_of_cmds->prev;
		i++;
	}
	return (list_of_cmds);
}
