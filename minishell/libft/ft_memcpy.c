/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agadkari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:08:04 by agadkari          #+#    #+#             */
/*   Updated: 2023/10/19 17:12:41 by agadkari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		((char *)ptr)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}
