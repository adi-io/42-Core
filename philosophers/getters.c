/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agadkari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:05:20 by agadkari          #+#    #+#             */
/*   Updated: 2024/03/20 15:06:23 by agadkari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_philo_dead(t_philo *philo)
{
	if (philo -> state == DEAD)
		return (1);
	return (0);
}

t_state	get_philo_state(t_philo *philo)
{
	t_state	state;

	pthread_mutex_lock(&philo -> mut_state);
	state = philo -> state;
	pthread_mutex_unlock(&philo -> mut_state);
	return (state);
}

uint64_t	get_last_meal_time(t_philo *philo)
{
	uint64_t	time;

	pthread_mutex_lock(&philo -> mut_last_eat_time);
	time = philo -> last_eat_time;
	pthread_mutex_unlock(&philo -> mut_last_eat_time);
	return (time);
}

int	get_nb_meals_had(t_philo *philo)
{
	int	meals;

	pthread_mutex_lock(&philo -> mut_nb_meals_had);
	meals = philo -> nb_meals_had;
	pthread_mutex_unlock(&philo -> mut_nb_meals_had);
	return (meals);
}

bool	get_keep_iter(t_data *data)
{
	bool	result;

	pthread_mutex_lock(&data -> mut_keep_iter);
	result = data -> keep_iterating;
	pthread_mutex_unlock(&data -> mut_keep_iter);
	return (result);
}
