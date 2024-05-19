/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minipwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 01:52:32 by mman              #+#    #+#             */
/*   Updated: 2024/05/19 01:54:46 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	mini_pwd(t_tools *tools, t_simple_cmds *simple_cmd)
{
	printf("\n%s\n", tools->pwd);
	printf(" -- simple_cmd->str[1] is %s -- ", simple_cmd->str[1]);
	return(EXIT_SUCCESS);
}
