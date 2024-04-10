#include "minishell.h"

t_simple_cmds	*ft_simple_cmdnew(char	**str, int num_redirections, t_lexer *redirections)
{
	t_simple_cmds	*new_element;

	new_element = (t_simple_cmds *)malloc(sizeof(t_simple_cmds));
	if (!new_element)
		return (0);
	new_element -> str;
	new_element -> builtin //no idea;
	new_element -> num_redirections = num_redirections;
	new_element -> hd_file_name = NULL;
	new_element -> redirections = redirections;
	new_element -> next = NULL;
	new_element -> prev = NULL;
	return (new_element);
}

void	ft_simple_cmd_addback(t_simple_cmds **lst, t_simple_cmds *new)
{
	t_simple_cmds *tmp;

	tmp = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return	;
	}
	while (!tmp -> next != NULL)
		tmp = tmp -> next;
	tmp -> next = new;
	tmp -> next -> prev = tmp;
}


