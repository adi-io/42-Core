/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:36:13 by agadkari          #+#    #+#             */
/*   Updated: 2024/04/25 20:42:32 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//todo: https://saturncloud.io/blog/difference-between-single-and-double-quotes-in-bash/#example-single-quotes

int	main(int argc, char **argv, char **envp)
{
	t_tools	tools;

	if (argc != 1 || argv[1])
	{
		printf("This program does not accept arguments");
		return (1);
	}
	tools.envp = ft_memmory(envp);
	// envpprint(tools);
	find_pwd(tools);
	init_tools(&tools);
	printf("\n\n-------\nWelcome! %s | MINISHELL:\n", getenv("LOGNAME"));
	minishell_loop(&tools);
	return (0);
}



// https://miro.com/welcomeonboard/VGZPY2g3R2ZTQmRDa2pCZXV6Q3lQYWZRNHZwYU1ubVZsdDRsSXZMcm92OEFMWWZWclNkQ3VMaTFxWGZOM1kwcHwzNDU4NzY0NTg3MDIyNjE1MzczfDI=?share_link_id=398465513011
