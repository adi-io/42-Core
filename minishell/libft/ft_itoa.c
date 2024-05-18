/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agadkari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:45:48 by agadkari          #+#    #+#             */
/*   Updated: 2023/10/21 17:10:30 by agadkari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	put_count(int a)
{
	int	n;

	n = 1;
	while (a >= 10)
	{
		a = (a / 10);
		n++;
	}
	return (n);
}

char	*put_print(int num, char *str)
{
	char	*temp_str;

	if (num >= 10)
		temp_str = put_print(num / 10, str);
	else
		temp_str = str;
	*temp_str = '0' + (num % 10);
	return (temp_str + 1);
}

char	*sp(void)
{
	char	*ptr;

	ptr = (char *)malloc(12);
	ptr[0] = '-';
	ptr[1] = '2';
	ptr[2] = '1';
	ptr[3] = '4';
	ptr[4] = '7';
	ptr[5] = '4';
	ptr[6] = '8';
	ptr[7] = '3';
	ptr[8] = '6';
	ptr[9] = '4';
	ptr[10] = '8';
	ptr[11] = '\0';
	return (ptr);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	char	*start;
	int		i;
	int		s;

	i = 0;
	s = 0;
	if (n == -2147483648)
		return (sp());
	if (n < 0)
	{
		n *= -1;
		s++;
	}
	i = put_count(n);
	ptr = (char *)malloc(i + s + 1);
	if (!(ptr))
		return (NULL);
	start = ptr;
	if (s > 0)
		ptr[0] = '-';
	ptr = put_print(n, (ptr + s));
	*ptr = '\0';
	return (start);
}
