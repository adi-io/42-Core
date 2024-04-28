/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 22:31:56 by mman              #+#    #+#             */
/*   Updated: 2024/04/23 22:48:43 by mman             ###   ########.fr       */
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