#include "minishell.h"

static void	append_char(char **tmp, char c)
{
	char	*tmp2;
	char	*tmp3;

	tmp2 = char_to_str(c);
	tmp3 = ft_strjoin(*tmp, tmp2);
	free(*tmp);
	*tmp = tmp3;
	free(tmp2);
}

static int	is_dollar_sign_valid(char *str, int i)
{
	return (str[i] == '$' && (str[i + 1] != ' '
		&& (str[i + 1] != '"' || str[i + 2] != '\0'))
		&& str[i + 1] != '\0' && str[i - 1] != '\'');
}

char	*detect_dollar_sign(t_tools *tools, char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_strdup("\0");
	while (str[i])
	{
		i += handle_digit_after_dollar(i, str);
		if (str[i] == '$' && str[i + 1] == '?')
			i += question_mark(&tmp);
		else if (is_dollar_sign_valid(str, i))
			i += loop_if_dollar_sign(tools, str, &tmp, i);
		else
			append_char(&tmp, str[i++]);
	}
	return (tmp);
}
