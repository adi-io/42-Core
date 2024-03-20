/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agadkari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:59:03 by agadkari          #+#    #+#             */
/*   Updated: 2024/03/20 14:59:05 by agadkari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t	get_eat_time(t_data *data)
{
	uint64_t	time;

	pthread_mutex_lock(&data -> mut_eat_time);
	time = data -> eat_time;
	pthread_mutex_unlock(&data -> mut_eat_time);
	return (time);
}

uint64_t	get_die_time(t_data *data)
{
	uint64_t	time;

	pthread_mutex_lock(&data -> mut_die_time);
	time = data -> die_time;
	pthread_mutex_unlock(&data -> mut_die_time);
	return (time);
}

uint64_t	get_sleep_time(t_data *data)
{
	uint64_t	time;

	pthread_mutex_lock(&data -> mut_sleep_time);
	time = data -> sleep_time;
	pthread_mutex_unlock(&data -> mut_sleep_time);
	return (time);
}

uint64_t	get_start_time(t_data *data)
{
	uint64_t	time;

	pthread_mutex_lock(&data -> mut_start_time);
	time = data -> start_time;
	pthread_mutex_unlock(&data -> mut_start_time);
	return (time);
}

int	get_nb_philos(t_data *data)
{
	int	nb;

	pthread_mutex_lock(&data -> mut_nb_philos);
	nb = data -> nb_philos;
	pthread_mutex_unlock(&data -> mut_nb_philos);
	return (nb);
}
