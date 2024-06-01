/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniexit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 03:28:34 by mman              #+#    #+#             */
/*   Updated: 2024/06/01 17:10:04 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//ensures no leaks (TODO) and exits
void	mini_exit(t_tools *tools)
{
    //todo free all shit?
    printf("\n");
	exit(EXIT_SUCCESS);
}
