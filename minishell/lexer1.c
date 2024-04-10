#include "minishell.h"

int	token_reader(t_tools *token)
{
	int	i;
	int	j;

	i = 0;
	while(tools -> args[i])
	{
		i+= rem_spaces(tools -> args[i]);
		if (check_token(tools -> args[i]))
			j = (handle_token(tools -> args[i], i, &tools -> lexer_list));
		else
			j = (read_words(tools -> args[i], &tools -> lexer_list));
		if (j < 0)
			return (1);
		i += j;
	}
	return (0);
}

int	handle_token(char *str, int i, t_lexer **lexer_list)
{
	t_token	token;

	token = check_token(str[i]);
	if (token == GREAT && check_token(str[i + 1]) == GREAT)
		add_node(NULL, GREAT_GREAT, lexer_list);
	else if (token == LESS && check_token(str[i + 1]) == LESS)
		add_node(NULL, LESS_LESS, lexer_list);
	else
		add_node(NULL, token, lexer_list);
	return (0);
}

t_token	check_token(int c)
{
	static int	token_arr[3][2] ={
		{'|', PIPE},
		{'<', LESS},
		{'>', MORE},
	}
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

int	add_node(char *str, t_token token, t_lexer **lexer_list)
{
	t_lexer	*node;

	node = ft_lexnew(str, token);
	if (!node)
		//handle error
	ft_lexaddback(node, lexer_list);
	return (0);
}

int	read_words(char *str, t_lexer **lexer_list)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i + j] && !check_token(str[i + j]))
	{
		j+= handle_quotes(i + j, str, 34);
		j+= handle_quotes(i + j, str, 39);
		if (ft_whitespace(str[i + j]))
			break;
		else
			j++;
	}
	if (!add_node(ft_substr(str, i, j), 0, lexer_list))
			//error handler
	return (j);
}




