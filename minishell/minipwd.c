/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minipwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 01:52:32 by mman              #+#    #+#             */
/*   Updated: 2024/05/19 03:36:25 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//pwd without any options
int	mini_pwd(t_tools *tools)
{
    printf("\nEXECUTING PWD\n\n\n");
	printf("\n%s\n", tools->pwd);
    printf("END OF PWD\n\n\n");
	return(EXIT_SUCCESS);
}
