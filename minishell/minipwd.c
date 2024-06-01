/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minipwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 01:52:32 by mman              #+#    #+#             */
/*   Updated: 2024/06/01 17:10:10 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//pwd without any options
int	mini_pwd(t_tools *tools)
{
	printf("\n%s\n", tools->pwd);
	return(EXIT_SUCCESS);
}
