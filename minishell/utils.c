/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:31:12 by agadkari          #+#    #+#             */
/*   Updated: 2024/06/01 17:12:18 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_matching_quote(char *line, int i, int *num_del, int del)
{
	int		j;
	size_t	len;

	j = i + 1;
	*num_del += 1;
	len = strlen(line);
	while (j < (int)len && line[j] != del)
		j++;
	if (j < (int)len && line[j] == del)
		*num_del += 1;
	return (j - i);
}

static int	process_quotes(char *line, int *i
		, int *quote_count, char quote_type)
{
	int	j;

	j = find_matching_quote(line, *i, quote_count, quote_type);
	if (*i + j >= (int)ft_strlen(line))
		return (0);
	*i += j;
	return (1);
}

int	count_quotes(char *line)
{
	int		i;
	int		s;
	int		d;
	size_t	len;

	s = 0;
	d = 0;
	i = -1;
	len = ft_strlen(line);
	while (++i < (int)len)
	{
		if (line[i] == 34 && !process_quotes(line, &i, &d, 34))
			return (0);
		else if (line[i] == 39 && !process_quotes(line, &i, &s, 39))
			return (0);
	}
	if ((d > 0 && d % 2 != 0) || (s > 0 && s % 2 != 0))
		return (0);
	return (1);
}

char	**ft_arrdup(char **arr)
{
	char	**rtn;
	size_t	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	rtn = ft_calloc(sizeof(char *), i + 1);
	if (!rtn)
		return (NULL);
	i = 0;
	while (arr[i] != NULL)
	{
		rtn[i] = ft_strdup(arr[i]);
		if (rtn[i] == NULL)
		{
			free_arr(rtn);
			return (rtn);
		}
		i++;
	}
	return (rtn);
}
