/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:36:13 by agadkari          #+#    #+#             */
/*   Updated: 2024/07/12 21:34:07 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_tools	tools;

	if (argc != 1 || argv[1])
	{
		printf("This program does not accept arguments");
		return (1);
	}
	tools.envp = ft_arrdup(envp);
	find_pwd(&tools);
	implement_tools(&tools);
	minishell_loop(&tools);
	return (0);
}
