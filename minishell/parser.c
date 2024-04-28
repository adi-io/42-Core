/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:57:22 by agadkari          #+#    #+#             */
/*   Updated: 2024/04/28 11:56:41 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_parser_tools	init_parser_tools(t_lexer *lexer_list, t_tools *tools)
{
	t_parser_tools	parser_tools;

	parser_tools.lexer_list = lexer_list;
	parser_tools.redirections = NULL;
	parser_tools.num_redirections = 0;
	parser_tools.tools = tools;
	return (parser_tools);
}

int	parser(t_tools	*tools)
{
	t_simple_cmds	*node;
	t_parser_tools	parser_tools;
	int	i;

	i = 0;
	tools -> simple_cmds = NULL;

	ft_count_pipes(tools -> lexer_list, tools);
	if (tools -> lexer_list -> token == PIPE)
		return (1);

	while (tools -> lexer_list)
	{
		if (tools -> lexer_list -> token && tools -> lexer_list -> token == PIPE)
			ft_rm_lex(&tools -> lexer_list, tools -> lexer_list -> token);
	//	if (handle_pipe_error(tools, tools -> lexer_list -> token))
				//handle errror
		parser_tools = init_parser_tools(tools -> lexer_list, tools);
		node = init_cmd(&parser_tools);
		printf("Parsed command %d: %s\n", i, node->str[1]);
		if (!node)
			return (1);//handle error
		if (!tools -> simple_cmds)
			tools -> simple_cmds = node;
		else
			ft_simple_cmd_addback(&tools -> simple_cmds, node);
		tools -> lexer_list = parser_tools.lexer_list;
	}
	return (EXIT_SUCCESS);
}

void	ft_count_pipes(t_lexer *lexer_list, t_tools *tools)
{
	t_lexer	*arg;

	arg = lexer_list;
	tools -> pipes = 0;
	while (arg)
	{
		if (arg -> token == PIPE)
			tools ->pipes++;
		arg = arg -> next;
	}
}
