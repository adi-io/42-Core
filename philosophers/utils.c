/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agadkari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:01:17 by agadkari          #+#    #+#             */
/*   Updated: 2024/03/20 15:18:47 by agadkari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

bool	nb_meals_option(t_data *data)
{
	if (data -> nb_meals > 0)
		return (true);
	return (false);
}

void	print_msg(t_data *data, int id, char *msg)
{
	int64_t	time;

	time = get_time() - get_start_time(data);
	pthread_mutex_lock(&data -> mut_print);
	if (get_keep_iter(data))
		printf("%lu %d %s\n", time, id, msg);
	pthread_mutex_unlock(&data -> mut_print);
}

void	print_mut(t_data *data, char *msg)
{
	pthread_mutex_lock(&data -> mut_print);
	printf("%s\n", msg);
	pthread_mutex_unlock(&data -> mut_print);
}

void	sweaper(t_data *data)
{
	int	i;
	int	nb;

	nb = get_nb_philos(data);
	i = -1;
	while (++i < nb)
	{
		pthread_mutex_destroy(&data -> forks[i]);
		pthread_mutex_destroy(&data -> philos[i].mut_state);
		pthread_mutex_destroy(&data -> philos[i].mut_nb_meals_had);
		pthread_mutex_destroy(&data -> philos[i].mut_last_eat_time);
	}
	pthread_mutex_destroy(&data -> mut_die_time);
	pthread_mutex_destroy(&data -> mut_eat_time);
	pthread_mutex_destroy(&data -> mut_sleep_time);
	pthread_mutex_destroy(&data -> mut_nb_philos);
	pthread_mutex_destroy(&data -> mut_print);
	pthread_mutex_destroy(&data -> mut_keep_iter);
	pthread_mutex_destroy(&data -> mut_start_time);
	free(data -> philo_ths);
	free(data -> philos);
	free(data -> forks);
}
