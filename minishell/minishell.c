/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agadkari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:36:13 by agadkari          #+#    #+#             */
/*   Updated: 2024/04/11 16:06:23 by agadkari         ###   ########.fr       */
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
	tools.envp = ft_memmory(envp);
	find_pwd(&tools);
	init_tools(&tools);
	printf("Welcome Bros");
	minishell_loop(&tools);
	return (0);
}
