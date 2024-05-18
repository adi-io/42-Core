/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:59:26 by agadkari          #+#    #+#             */
/*   Updated: 2024/05/19 00:03:53 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_quotes(int i, char *str, int c)
{
	int	j;

	j = 0;
	if (str[i + j] == c)
	{
		j++;
		while (str[i + j] != c && str[i + j])
			j++;
		j++;
	}
	return (j);
}

int	ft_whitespace(char str)
{
	if (str == ' ')
		return (1);
	return (0);
}

int	read_words(int i, char *str, t_lexer **lexer_list)
{
	int	j;

	j = 0;
	while (str[i + j] && !ft_whitespace(str[i + j]) && !check_token(str[i + j]))
		j++;
	add_node(ft_substr(str, i, j), WORD, lexer_list);
	return (j);
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

//returns 1 if no
//returns 0 if yes
int	count_quotes(char *str) //not sure if this work for all cases
{
	int	i;
	int	s;
	int	d;

	i = -1;
	s = 0;
	d = 0;

	while (str[++i])
	{
		if (str[i] == '\"')
			s += find_other_pair(str, i, &d, 34);
		else if (str[i] == '\'')
			s += find_other_pair(str, i, &d, 39);
	}
	if ((s > 0 && s % 2 != 0) || (d > 0 && d % 2 != 0))
		return (1);
	return (0);
}

void print_commands(t_simple_cmds *head) {
    while (head != NULL) {
        printf("[SYSTEM CALL LOG] Command: ");
        for (int i = 0; head->str && head->str[i]; i++) {
            printf("%s ", head->str[i]);
        }

        // Print redirections
        t_lexer *redir = head->redirections;
        while (redir) {
            printf("  Redirection: %s %s\n", redir->str, redir->next->str); // Assuming redirection token is followed by filename
            redir = redir->next->next; // Move to the next redirection pair
        }

        head = head->next;
    }
}


int	minishell_loop(t_tools *tools)
{
	char	*temp;
	int	i;

	i = 0;
	temp = readline("$> ");
	if (temp == NULL)
		return (-1);
	tools->args = ft_strdup(temp);
	temp = ft_strtrim(tools -> args, " ");
	tools->args = temp;
	if (!tools -> args)
		return (EXIT_FAILURE);
	else if (!tools -> args[0])
		return (EXIT_FAILURE);
	add_history(tools -> args);
	if (count_quotes(tools -> args))
		return (EXIT_FAILURE);
	if (token_reader(tools))
		return (EXIT_FAILURE);
	parser(tools);
	print_commands(tools -> simple_cmds);
	executer_enter(tools);
	printf("-- end of the loop [SYSTEM CALL LOG]\n");
	//TODO reset function
	minishell_loop(tools); //very simple loop by recursion
	return (0);
}
