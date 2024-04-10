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
		// error handler
	if (!token_reader(tools -> args))
		//TODO TOKENIZER
	parser(tools); //TODO
	//Write excecuter
	//reset function
	return (0);
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

int	count_qoutes(char *str) //not sure if this work for all cases
{
	int	i;
	int	s;
	int	d;

	i = -1;
	s = 0;
	d = 0;

	while (str[++i])
	{
		if (str[i] == 34)
			i += find_other_pair(str, i, &d, 34);
		if (str[i] == 39)
			i += find_other_pair(str, i, &d, 39);
	}
	if ((s > 0 && s % 2 != 0) || (d > 0 && d % 2 != 0))
		return (1);
	return (1);
}




































