/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniecho.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 01:59:24 by mman              #+#    #+#             */
/*   Updated: 2024/07/12 20:47:59 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	mini_echo(t_tools *tools, t_simple_cmds *simple_cmd)
{
	int	i;
	int	toggle;

	i = 1;
	toggle = FALSE;
	if (!simple_cmd->str[i])
		return (EXIT_FAILURE);
	else if (!ft_strncmp("-n", simple_cmd->str[i], 1))
	{
		toggle = TRUE;
		i++;
	}
	while (simple_cmd->str[i])
	{
		printf ("%s", simple_cmd->str[i]);
		if (simple_cmd->str[i + 1])
			printf(" ");
		i++;
	}
	if (toggle)
		printf("\n");
	return (EXIT_SUCCESS);
}
