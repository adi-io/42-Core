#include "minishell.h"

int	init_cmd(t_parser_tools *parser_tools)
{
	char	*str;
	int	j;
	int	arg_size;
	t_lexer	*tmp;

	i = 0;
	rm_redirections(parser_tools);
	arg_size = count_args(parser_tools -> lexer_list);
	str = ft_calloc(arg_size + 1, sizeof(char *));
	if (!str)
		//handle error
	while (arg_size > 0)
	{
		if (tmp -> str)
		{
			str[i++] = ft_strdup(tmp->str);
			ft_rem_lex(&parser_tools -> lexer_list, tmp -> i);
			tmp = parser_tools -> lexer_list
		}
		arg_size--;
	}
	return (ft_simple_cmdsnew(str, parser_tools -> num_redirections, parser_tools -> redirections));
}

void	rm_redirections(t_parser_tools *parser_tools)
{
	t_lexer *tmp;

	tmp = parser_tools -> lexer_list;
	while (tmp -> token == 0)
		temp = tmp -> nect;
	if (!tmp || tmp -> token == PIPE)
		//throw error
	if (tmp -> next -> token)
		// two token twice, throw error
	if ((tmp -> token >= GREAT && tmp -> token <= LESS_LESS))
		add_new_redirection(tmp, parser_tools);
	rm_redirections(parser_tools);
}

void	add_new_redirection(t_lexer *lexer_list, t_parser_tools *parser_tools)
{
	t_lexer	*node;
	int	index_1;
	int	index_2;

	node = ft_lex_new(ft_strdup(tmp -> next -> str), tmp -> token);
	if (!node)
		//handle error
	ft_lex_add_back(&parser_tools -> redirections, node);
	index_1 = tmp -> i;
	index_2 = tmp -> next -> i;
	ft_rem_lex(&parser_tools -> lexer_list, index_1);
	ft_rem_lex(&parser_tools -> lexer_list, index_2);
	parser_tools -> num_redirections++;
}




















