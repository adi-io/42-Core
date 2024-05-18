/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agadkari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:12:23 by agadkari          #+#    #+#             */
/*   Updated: 2023/10/19 17:00:10 by agadkari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s2 < s1)
	{
		i = n;
		while (i--)
			((unsigned char *) s1)[i] = ((unsigned char *) s2)[i];
	}
	else
	{
		while (i < n)
		{
			((unsigned char *) s1)[i] = ((unsigned char *) s2)[i];
			i++;
		}
	}
	return (s1);
}
