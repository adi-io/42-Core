/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agadkari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:56:15 by agadkari          #+#    #+#             */
/*   Updated: 2024/04/11 17:29:02 by agadkari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lexer	*ft_rem_lexstr(t_lexer **lexer_list)
{
	if ((*lexer_list) -> str)
	{
		free((*lexer_list) -> str);
		(*lexer_list) -> str = NULL;
	}
	free (*lexer_list);
	*lexer_list = NULL;
	return (NULL);
}

void	ft_rem_first(t_lexer **lexer_list)
{
	t_lexer *temp;

	temp = *lexer_list;
	*lexer_list = temp -> next;
	ft_rem_lexstr(&temp);
	if (*lexer_list)
		(*lexer_list) -> prev = NULL;
}

void	ft_rm_lex(t_lexer **lexer_list, int key)
{
	t_lexer	*node;
	t_lexer *prev;
	t_lexer *start;

	start = *lexer_list;
	node = start;
	if ((*lexer_list) -> i == key)
	{
		ft_rem_first(lexer_list);
		return ;
	}
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

t_lexer	*ft_lexernew(char *str, int token)
{
	t_lexer		*new_element;
	static int	i = 0;

	new_element = (t_lexer *)malloc(sizeof(t_lexer));
	if (!new_element)
		return (0);
	new_element->str = str;
	new_element->token = token;
	new_element->i = i++;
	new_element->next = NULL;
	new_element->prev = NULL;
	return (new_element);
}

void	ft_lexaddback(t_lexer **lst, t_lexer *new)
{
	t_lexer	*tmp;

	tmp = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}
