/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agadkari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:55:23 by agadkari          #+#    #+#             */
/*   Updated: 2023/10/20 19:14:48 by agadkari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	unsigned int	i;
	char			*ptr;
	char			temp;

	i = 0;
	ptr = (char *)malloc(ft_strlen(s) + 1);
	if (!(ptr))
		return (NULL);
	while (s[i])
	{
		temp = s[i];
		ptr[i] = f(i, temp);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
