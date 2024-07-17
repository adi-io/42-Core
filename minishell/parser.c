/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:57:22 by agadkari          #+#    #+#             */
/*   Updated: 2024/06/01 17:10:29 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_simple_cmds	*init_cmd(t_parser_tools *parser_tools)
{
	char	**str;
	int		i;
	int		arg_size;
	t_lexer	*tmp;

	i = 0;
	rm_redirections(parser_tools);
	arg_size = count_args(parser_tools->lexer_list);
	str = ft_calloc(arg_size + 1, sizeof(char *));
	if (!str)
		parser_error(1, parser_tools->tools, parser_tools->lexer_list);
	tmp = parser_tools->lexer_list;
	while (arg_size > 0)
	{
		if (tmp->str)
		{
			str[i++] = ft_strdup(tmp->str);
			ft_lexerdelone(&parser_tools->lexer_list, tmp->i);
			tmp = parser_tools->lexer_list;
		}
		arg_size--;
	}
	return (ft_simple_cmdsnew(str,
			parser_tools->num_redirections, parser_tools->redirections));
}

int	handle_pipe_errors(t_tools *tools, t_tokens token)
{
	if (token == PIPE)
	{
		parser_double_token_error(tools, tools->lexer_list,
			tools->lexer_list->token);
		return (EXIT_FAILURE);
	}
	if (!tools->lexer_list)
	{
		parser_error(0, tools, tools->lexer_list);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	handle_node(t_tools *tools, t_parser_tools *parser_tools)
{
	t_simple_cmds	*node;

	*parser_tools = init_parser_tools(tools->lexer_list, tools);
	node = init_cmd(parser_tools);
	if (!node)
	{
		parser_error(0, tools, parser_tools->lexer_list);
		return (EXIT_FAILURE);
	}
	if (!tools->simple_cmds)
		tools->simple_cmds = node;
	else
		ft_simple_cmdsadd_back(&tools->simple_cmds, node);
	tools->lexer_list = parser_tools->lexer_list;
	return (EXIT_SUCCESS);
}

static int	process_lexer_list(t_tools *tools, t_parser_tools *parser_tools)
{
	while (tools->lexer_list)
	{
		if (tools->lexer_list->token == PIPE)
		{
			ft_lexerdelone(&tools->lexer_list, tools->lexer_list->i);
			if (!tools->lexer_list)
			{
				parser_error(0, tools, NULL);
				return (EXIT_FAILURE);
			}
		}
		if (handle_pipe_errors(tools, tools->lexer_list->token))
			return (EXIT_FAILURE);
		if (handle_node(tools, parser_tools) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	parser(t_tools *tools)
{
	t_parser_tools	parser_tools;

	tools->simple_cmds = NULL;
	if (!tools->lexer_list)
		return (EXIT_SUCCESS);
	count_pipes(tools->lexer_list, tools);
	if (tools->lexer_list->token == PIPE)
	{
		parser_double_token_error(tools, tools->lexer_list,
			tools->lexer_list->token);
		return (EXIT_FAILURE);
	}
	return (process_lexer_list(tools, &parser_tools));
}
