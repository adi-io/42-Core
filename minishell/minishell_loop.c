/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:59:26 by agadkari          #+#    #+#             */
/*   Updated: 2024/04/28 11:14:16 by mman             ###   ########.fr       */
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

//returns 1 if no
//returns 0 if yes
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
		if (str[i] == '\"')
			i += find_other_pair(str, i, &d, 34);
		else if (str[i] == '\'')
			i += find_other_pair(str, i, &d, 39);
	}
	if ((s > 0 && s % 2 != 0) || (d > 0 && d % 2 != 0))
		return (1);
	return (1);
}

/* Incorrect Balanced Quote Logic: The logic ((s > 0 && s % 2 != 0) || (d > 0 && d % 2 != 0)) isn't a reliable way to determine if quotes are balanced. Consider these cases that would incorrectly return true (indicating unbalanced):
"hello'": Single quotes balanced, double quotes unbalanced.
'hello"world"': Both single and double quotes unbalanced.
Incomplete Handling of Nested Quotes: The code doesn't adequately handle nested quotes. Consider a string like "hello 'world'". The find_other_pair will skip to the end of the string, causing incorrect results.
 */

int	minishell_loop(t_tools *tools)
{
	char	*temp;

	temp = readline("$> ");
	if (temp == NULL)
			return (-1);
	tools->args = ft_strdup(temp);
	temp = ft_strtrim(tools -> args, " ");
	tools->args = temp;
	if (!tools -> args)
		return (EXIT_FAILURE);
	else if (!tools -> args[0])
		return (EXIT_FAILURE);
	add_history(tools -> args);
	if (!count_quotes(tools -> args))
		return (EXIT_FAILURE);
	// Bellow generally returns 1
	if (token_reader(tools))
		return (EXIT_FAILURE);
	//ABOVE CODE WORKSSSS -- Parser SEGFAU. 24/04/20;58 NOTE
	parser(tools);
	executer(tools);
	//TODO Write excecuter
	//TODO reset function
	return (0);
}
