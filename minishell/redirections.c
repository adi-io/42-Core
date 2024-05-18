/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agadkari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:03:07 by agadkari          #+#    #+#             */
/*   Updated: 2024/04/11 16:29:37 by agadkari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_args(t_lexer *lexer_list)
{
	t_lexer	*tmp;
	int		i;

	i = 0;
	tmp = lexer_list;
	while (tmp && tmp->token != PIPE)
	{
		if (tmp->i >= 0)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

t_simple_cmds	*init_cmd(t_parser_tools *parser_tools)
{
	char	**str;
	int	i;
	int	arg_size;
	t_lexer	*tmp;

	i = 0;
	rm_redirections(parser_tools);
	arg_size = count_args(parser_tools -> lexer_list);
	str = ft_calloc(arg_size + 1, sizeof(char *));
	if (!str)
		return (0);
	tmp = parser_tools -> lexer_list;
	while (arg_size > 0)
	{
		if (tmp -> str)
		{
			str[i++] = ft_strdup(tmp->str);
			ft_rm_lex(&parser_tools -> lexer_list, tmp -> i);
			tmp = parser_tools -> lexer_list;
		}
		arg_size--;
	}
	return (ft_simple_cmdnew(str, parser_tools -> num_redirections, parser_tools -> redirections));
}

void	rm_redirections(t_parser_tools *parser_tools)
{
	t_lexer *tmp;

	tmp = parser_tools -> lexer_list;
	while (tmp && tmp -> token == 0)
		tmp = tmp -> next;
	if (!tmp || tmp -> token == PIPE)
		return ;
	if (!tmp -> next)
		return ;
	if (tmp -> next -> token)
		return ;

	if ((tmp -> token >= GREAT && tmp -> token <= LESS_LESS))
			add_new_redirection(tmp, parser_tools);
	rm_redirections(parser_tools);
}

int	add_new_redirection(t_lexer *tmp, t_parser_tools *parser_tools)
{
	t_lexer	*node;
	int	index_1;
	int	index_2;

	node = ft_lexernew(ft_strdup(tmp -> next -> str), tmp -> token);
	if (!node)
		return (1);
	ft_lexaddback(&parser_tools -> redirections, node);
	index_1 = tmp -> i;
	index_2 = tmp -> next -> i;
	ft_rm_lex(&parser_tools -> lexer_list, index_1);
	ft_rm_lex(&parser_tools -> lexer_list, index_2);
	parser_tools -> num_redirections++;
	return (0);
}
