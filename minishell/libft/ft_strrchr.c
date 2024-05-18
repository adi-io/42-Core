/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agadkari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:31:47 by agadkari          #+#    #+#             */
/*   Updated: 2023/10/21 18:39:51 by agadkari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int i)
{
	unsigned char		*str;
	unsigned char		ch;
	size_t				l;

	str = (unsigned char *)s;
	ch = (unsigned char)i;
	l = 0;
	while (str[l])
		l++;
	if (ch == '\0')
		return ((char *)str + l);
	while (l--)
	{
		if (str[l] == ch)
			return ((char *)str + l);
	}
	return (0);
}
