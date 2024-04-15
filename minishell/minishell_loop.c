/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agadkari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:59:26 by agadkari          #+#    #+#             */
/*   Updated: 2024/04/11 16:17:50 by agadkari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_quotes(int i, char *str, int c)
{
	int	j;

	j = 0;
	if (str[i + j] == c)
	{
		j++;
		while (str[i + j] != c && str[i + j])
			j++;
		j++;
	}
	return (j);
}

int	ft_whitespace(char str)
{
	if (str == ' ')
		return (1);
	return (0);
}

int	read_words(int i, char *str, t_lexer **lexer_list)
{
	int	j;

	j = 0;
	while (str[i + j] && !check_token(str[i + j]))
	{
		j += handle_quotes(i + j, str, 34);
		j += handle_quotes(i + j, str, 39);
		if (ft_whitespace(str[i + j]))
			break;
		else
			j++;
	}
	if (!add_node(ft_substr(str, i, j), 0, lexer_list))
		return (1);
	return (j);
}

int	find_other_pair(char *str, int i, int *int_del, int del)
{
	int	j;

	j = i + 1;
	*int_del += 1;
	while (str[j] && str[j] != del)
		j++;
	if (str[j] == del)
		*int_del += 1;
	return (j - i);
}

int	count_quotes(char *str) //not sure if this work for all cases
{
	int	i;
	int	s;
	int	d;

	i = -1;
	s = 0;
	d = 0;

	while (str[++i])
	{
		if (str[i] == 34)
			i += find_other_pair(str, i, &d, 34);
		if (str[i] == 39)
			i += find_other_pair(str, i, &d, 39);
	}
	if ((s > 0 && s % 2 != 0) || (d > 0 && d % 2 != 0))
		return (1);
	return (1);
}

int	minishell_loop(t_tools *tools)
{
	char	*temp;

	tools -> args = readline("you like bash?:");
	temp = ft_strtrim(tools -> args, " ");
	free(tools -> args);
	tools -> args = temp;
	if (!tools -> args)
		return (1);
	if (!tools -> args[0])
		return (1);
	add_history(tools -> args);
	if (!count_quotes(tools -> args))
		return (1);
	if (!token_reader(tools))
		return (1);
	parser(tools);
	//TODO Write excecuter
	//TODO reset function
	return (0);
}
