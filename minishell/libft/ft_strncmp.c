/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agadkari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:28:32 by agadkari          #+#    #+#             */
/*   Updated: 2023/10/21 18:34:52 by agadkari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char		*st1;
	unsigned char		*st2;
	size_t				i;

	st1 = (unsigned char *)s1;
	st2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (st1[i] != st2[i] || st1[i] == '\0' || st2[i] == '\0')
			return ((int )st1[i] - (int )st2[i]);
		i++;
	}
	return (0);
}
