#include "minishell.h"

size_t	equal_sign(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (i + 1);
		i++;
	}
	return (0);
}

int	loop_if_dollar_sign(t_tools *tools, char *str, char **tmp, int j)
{
	int		k;
	int		ret;
	char	*tmp2;
	char	*tmp3;
	while (tools -> envp[k])
	{
		if (ft_strncmp(str + j + 1, tools -> envp[k], equal_sign(tools -> envp[k]) - 1) == 0
				&& after_dol_lenght(str, j) - j == (int)equal_sign(tools -> envp[k]))
		{
			tmp2 = ft_strdup(tools -> envp[k] + equal_sign(tools -> envp[k]));
			tmp3 = ft_strjoin(*tmp, tmp2);
			free(*tmp);
			*tmp = tmp3;
			free(tmp2);
			ret = equal_sign(tools->envp[k]);
		}
		k++;
	}
	if (ret == 0)
		ret = after_dol_lenght(str, j);
	return (ret);
}

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

char	*detect_dollar_sign(t_tools *tools, char *str)
{
	int		i;
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	i = 0;
	tmp = ft_strdup("\0");
	while (str[i])
	{
		i += handle_digit_after_dollar(i, str);
		if (str[i] == '$' && str[i + 1] == '?')
			i += question_mark(&tmp);
		else if (str[i] == '$' && (str[i + 1] != ' ' && (str[i + 1] != '"'
						|| str[i + 2] != '\0')) && str[i + 1] != '\0')
			i += loop_if_dollar_sign(tools, str, &tmp, i);
		else {
			tmp2 = char_to_str(str[i++]);
			tmp3 = ft_strjoin(tmp, tmp2);
			free(tmp);
			tmp = tmp3;
			free(tmp2);
		}
	}
	return (tmp);
}


char	*expand_str(t_tools *tools, char *str)
{
	char	*tmp;

	tmp = NULL;
	if (str[dollar_sign(str) - 2] != '\'' && dollar_sign(str) != 0
			&& str[dollar_sign(str)] != '\0')
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
	tmp = NULL;
	while (str[i] != NULL)
	{
		if (str[i][dollar_sign(str[i]) - 2] != '\'' && dollar_sign(str[i]) != 0
				&& str[i][dollar_sign(str[i])] != '\0')
		{
			tmp = detect_dollar_sign(tools, str[i]);
			free(str[i]);
			str[i] = tmp;
		}
		if (ft_strncmp(str[0], "export", ft_strlen(str[0]) - 1) != 0)
		{
			str[i] = delete_quotes(str[i], '\"');
			str[i] = delete_quotes(str[i], '\'');
		}
		i++;
	}
	return (str);
}
