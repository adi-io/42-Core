#include "minishell.h"

int	minishell_loop(t_tools *tools)
{
	char	*temp;

	tools -> args = readline("you like bash?:");
	temp = strtrim(tools -> args, " ");
	free(tools -> args);
	tools -> args = temp;
	if (!temp -> args)
		//Error handler
	if (!args[0])
		//Erro handler -> reset function
	add_history(tools -> args);
	if (!count_qoutes(tools -> args))
		// TODO function -> check if all quotes closed
	if (!token_reader(tools -> args))
		//TODO TOKENIZER
	parser(tools); //TODO
	//Write excecuter
	//reset function
	return (0);
}


