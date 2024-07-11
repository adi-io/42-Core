/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:16:17 by agadkari          #+#    #+#             */
/*   Updated: 2024/06/01 17:10:36 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_whitespace(char c)
{
	return (c == ' ' || (c > 8 && c < 14));
}

int	skip_spaces(char *str, int i)
{
	int	j;

	j = 0;
	while (is_whitespace(str[i + j]))
		j++;
	return (j);
}

int	add_node(char *str, t_tokens token, t_lexer **lexer_list)
{
	t_lexer	*node;

	node = ft_lexernew(str, token);
	if (!node)
		return (0);
	ft_lexeradd_back(lexer_list, node);
	return (1);
}

int	read_words(int i, char *str, t_lexer **lexer_list, size_t str_len)
{
	int		j;
	char	*substr;

	j = 0;
	while ((i + j) < str_len && str[i + j] && !(check_token(str[i + j])))
	{
		j += handle_quotes(i + j, str, 34);
		j += handle_quotes(i + j, str, 39);
		if (is_whitespace(str[i + j]))
			break ;
		else
			j++;
	}
	substr = ft_substr(str, i, j);
	if (!substr || !add_node(substr, 0, lexer_list))
	{
		free(substr);
		return (-1);
	}
	return (j);
}

int	token_reader(t_tools *tools)
{
	int		i;
	int		j;
	size_t	args_len;

	i = 0;
	args_len = strlen(tools->args);
	while (i < args_len && tools->args[i])
	{
		j = 0;
		i += skip_spaces(tools->args, i);
		if (i < args_len && check_token(tools->args[i]))
			j = handle_token(tools->args, i, &tools->lexer_list);
		else
			j = read_words(i, tools->args, &tools->lexer_list, args_len);
		if (j < 0)
		{
			return (0);
		}
		i += j;
	}
	return (1);
}
