/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agadkari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:20:18 by agadkari          #+#    #+#             */
/*   Updated: 2023/10/21 18:29:16 by agadkari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned char	*str02;
	int				i;
	int				j;
	int				num;

	i = 0;
	j = 1;
	num = 0;
	str02 = (unsigned char *)str;
	while (str02[i] == ' ' || (str02[i] >= 9 && str02[i] <= 13))
		i++;
	if (str02[i] == '-')
	{
		j = -1;
		i++;
	}
	else if (str02[i] == '+')
		i++;
	while (str02[i] >= '0' && str02[i] <= '9')
	{
		num *= 10;
		num += str02[i] - '0';
		i++;
	}
	return (num * j);
}
