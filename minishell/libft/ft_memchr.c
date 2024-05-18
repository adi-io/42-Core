/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agadkari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:00:34 by agadkari          #+#    #+#             */
/*   Updated: 2023/10/20 19:30:05 by agadkari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	i;

	i = (unsigned char)c;
	str = (unsigned char *)s;
	while (n--)
	{
		if (*str == i)
			return (str);
		str++;
	}
	return (NULL);
}
