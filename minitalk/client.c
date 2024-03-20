/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agadkari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:30:52 by agadkari          #+#    #+#             */
/*   Updated: 2024/03/06 17:07:54 by agadkari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>

int	ft_atoi(const char *str);

void	ft_encoder(char byte, int pid)
{
	int	i;
	int	bit;

	i = 8;
	while (i > 0)
	{
		i--;
		bit = (byte >> i);
		if (bit % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(500);
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i])
		{
			ft_encoder(argv[2][i], pid);
			i++;
		}
		ft_encoder('\0', pid);
	}
	else
		write(1, "\n", 1);
	return (0);
}

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
