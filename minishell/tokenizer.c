/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:16:17 by agadkari          #+#    #+#             */
/*   Updated: 2024/04/28 11:05:14 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_whitespace(char c)
{
	return (c == ' ' || (c > 8 && c < 14));
}

int	rem_spaces(char *str, int i)
{
	int	j;

	j = 0;
	while (is_whitespace(str[i + j]))
		j++;
	return (j);
}

// MMAN wokin on DS RIGHT NOOOOWWWWW   --- start APR 24 21:05
// if it finds a TOKEN it returns 0
// if ti sfinds a WORD ("") it returns 0
// else it returns 1
int	token_reader(t_tools *tools)
{
	int	i;
	int	j;

	i = 0;
	printf("token reader args: %s", tools->args);
	while (tools -> args[i])
	{
		j = 0;
		i += rem_spaces(tools -> args, i);
		if (check_token(tools -> args[i]))
			j = (handle_token(tools -> args, i, &tools -> lexer_list));
		else
			j = (read_words(i, tools -> args, &tools -> lexer_list));
		if (j < 0)
			return (1);
		i += j;
	}
	return (0);
}

// https://miro.com/app/board/uXjVKPNwyKk=/
int	handle_token(char *str, int i, t_lexer **lexer_list)
{
	t_tokens	token;

	token = check_token(str[i]);
	if (token == GREAT && check_token(str[i + 1]) == GREAT)
		add_node(NULL, GREAT_GREAT, lexer_list);
	else if (token == LESS && check_token(str[i + 1]) == LESS)
		add_node(NULL, LESS_LESS, lexer_list);
	else
		add_node(NULL, token, lexer_list);
	return (0);
}

t_tokens	check_token(int c)
{
	static int	token_arr[3][2] ={
		{'|', PIPE},
		{'>', GREAT},
		{'>', LESS},
	};
	int	i;

	i = 0;
	while (i < 3)
	{
		if (token_arr[i][0] == c)
			return (token_arr[i][1]);
		i++;
	}
	return (0);
}

int	add_node(char *str, t_tokens token, t_lexer **lexer_list)
{
	t_lexer	*node;

	node = ft_lexernew(str, token);
	if (!node)
		return (1);
	ft_lexaddback(lexer_list, node);
	return (0);
}
