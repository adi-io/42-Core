/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:09:38 by mman              #+#    #+#             */
/*   Updated: 2024/07/12 21:20:45 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_digit_after_dollar(int j, char *str)
{
	int	i;

	i = j;
	if (str[j] == '$')
	{
		if (ft_isdigit(str[j + 1]) == 1)
			j += 2;
	}
	return (j - i);
}

char	*expand_str(t_tools *tools, char *str)
{
	char	*tmp;
	size_t	dollar_pos;

	if (!str)
		return (NULL);
	tmp = NULL;
	dollar_pos = dollar_sign(str);
	if (dollar_pos > 2 && str[dollar_pos - 2] != '\''
		&& str[dollar_pos] != '\0')
	{
		tmp = detect_dollar_sign(tools, str);
		free(str);
		str = tmp;
	}
	str = delete_quotes(str, '\"');
	str = delete_quotes(str, '\"');
	return (str);
}

char	**expander(t_tools *tools, char **str)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i] != NULL)
	{
		if (str[i][0] != '\0' && dollar_sign(str[i]) != 0 &&
				str[i][dollar_sign(str[i]) - 1] != '\'' &&
				str[i][dollar_sign(str[i])] != '\0')
		{
			tmp = detect_dollar_sign(tools, str[i]);
			free(str[i]);
			str[i] = tmp;
		}
		if (str[0] && ft_strncmp(str[0], "export", ft_strlen("export")) != 0)
		{
			str[i] = delete_quotes(str[i], '\"');
		}
		i++;
	}
	return (str);
}
