/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agadkari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:24:09 by agadkari          #+#    #+#             */
/*   Updated: 2023/10/20 18:47:03 by agadkari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	sizedst;
	size_t	sizesrc;
	size_t	i;

	sizedst = ft_strlen(dst);
	sizesrc = ft_strlen(src);
	i = 0;
	if (size <= sizedst)
		return (size + sizesrc);
	while (src[i] && (sizedst + i < size - 1))
	{
		dst[sizedst + i] = src[i];
		i++;
	}
	if (sizedst + i < size)
		dst[sizedst + i] = '\0';
	return (sizedst + sizesrc);
}
