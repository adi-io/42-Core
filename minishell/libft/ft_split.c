/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agadkari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:44:53 by agadkari          #+#    #+#             */
/*   Updated: 2023/10/21 18:53:17 by agadkari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	wordcount(char const *s, char c)
{
	int	i;
	int	count;

	if (!s)
		return (0);
	i = 0;
	count = 0;
	while (s[i])
	{
		if ((s[i] != c) && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

char	*scpy(char const *str, char *ptr, int start, int end)
{
	int	i;

	if (!ptr)
		return (NULL);
	i = 0;
	while (start < end)
	{
		ptr[i] = str[start];
		start++;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*get_word(char const *s, char c, int *index)
{
	char	*ptr2;
	int		len;
	int		start_index;

	if (!(s))
		return (NULL);
	while (s[*index] == c)
		(*index)++;
	len = 0;
	start_index = *index;
	while (s[*index] != c && s[*index])
	{
		len++;
		(*index)++;
	}
	ptr2 = (char *)malloc(len + 1);
	if (!(ptr2))
		return (NULL);
	scpy(s, ptr2, start_index, *index);
	return (ptr2);
}

void	free_words(char **ptr, int i)
{
	while (--i >= 0)
		free(ptr[i]);
	free (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		word_num;
	int		i;
	int		j;

	if (!(s))
		return (NULL);
	i = 0;
	j = 0;
	word_num = wordcount(s, c);
	ptr = (char **)malloc((word_num + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	while (i < word_num)
	{
		ptr[i] = get_word(s, c, &j);
		if (!(ptr[i]))
		{
			free_words (ptr, i);
			return (NULL);
		}
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}
