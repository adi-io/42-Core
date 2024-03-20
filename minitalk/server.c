/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agadkari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:33:16 by agadkari          #+#    #+#             */
/*   Updated: 2024/03/06 15:19:53 by agadkari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>

void	handle_signal(int signal)
{
	static unsigned char	current_char;
	static int				bit_index;

	current_char <<= 1;
	if (signal == SIGUSR1)
		current_char |= 1;
	else
		current_char |= 0;
	bit_index++;
	if (bit_index == 8)
	{
		write(1, &current_char, 1);
		current_char = 0;
		bit_index = 0;
	}
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char		*ptr;
	size_t				i;

	ptr = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		ptr[i] = c;
		i++;
	}
	return (b);
}

int	main(void)
{
	struct sigaction	act;

	ft_memset(&act, 0, sizeof(act));
	printf("%d\n", getpid());
	act.sa_handler = &handle_signal;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
	return (0);
}
