#include "minishell.h"

int	parser(t_tools	*tools)
{
	t_simple_cmd	*node;
	t_parser_tools	parser_tools;

	tools -> simple_cmd = NULL;
	ft_count_pipes(tools -> lexer_list, tools);
	if (tools -> lexer_list -> token == PIPE)
		//handle error
	while (tools -> lexer_list)
	{
		if (tools -> lexer_tools -> token && tools -> lexer_tools -> token == PIPE)
			//TODO ft_lexerdel
		if (handle_pipe_error(tools, tools -> lexer_tools -> token))
				//handle errror

		parser_tools = init_parser_tools(tools -> lexer_list, tools);
		node = init_cmd(parser_tools);
		if (!node)
			//handle error
		if (!tools -> simple_cmd)
			tools -> simple_cmd = node;
		else
			ft_simple_cmdadd_back(&tools -> simple_cmd, node);
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

void	ft_rem_lexstr(t_lexer **lexer_list)
{
	if (*lexer_list -> str)
	{
		free((*lexer_list) -> str);
		(*lexer_list) -> NULL;
	}
	free (*lexer_list);
	*lexer_list = NULL;
}

void	fr_rem_first(t_lexer **lexer_list)
{
	t_lexer *temp;

	temp = *lexer_list;
	*lexer_list = temp -> next;
	ft_rem_lexstr(&temp);
	if (lexer_list)
		lexer_list -> prev = NULL;
}


int	ft_rm_lex(t_lexer **lexer_list, int key)
{
	t_lexer	*node;
	t_lexer *prev;
	t_lexer *start;

	start = *lexer_list;
	node = start;
	if ((*lexer_list) -> i == key)
	{
		ft_rem_lex(node);
		return ;
	}
	else
	{
		while (node && node -> i != key)
		{
			prev = node;
			node = node -> next;
		}
		if (node)
			node -> prev = node -> next;
		else
			prev -> next = NULL;
		if (prev -> next)
			prev -> next -> prev = prev;
		ft_rem_lexstr(&node);
		*lexer_list = start;
	}
}














