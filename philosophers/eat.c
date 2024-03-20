/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agadkari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:58:28 by agadkari          #+#    #+#             */
/*   Updated: 2024/03/20 15:05:09 by agadkari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_forks(t_philo *philo)
{
	if (get_nb_philos(philo -> data) == 1)
		return (handle_one_philo(philo));
	if (take_right_fork(philo))
		return (1);
	if (take_left_fork(philo))
	{
		drop_right_fork(philo);
		return (1);
	}
	return (0);
}

void	update_last_meal_time(t_philo *philo)
{
	pthread_mutex_lock(&philo -> mut_last_eat_time);
	philo -> last_eat_time = get_time();
	pthread_mutex_unlock(&philo -> mut_last_eat_time);
}

void	wait_for_eating(t_data *data)
{
	ft_usleep(get_sleep_time(data));
}

void	update_meals_had(t_philo *philo)
{
	pthread_mutex_lock(&philo -> mut_nb_meals_had);
	philo -> nb_meals_had++;
	pthread_mutex_unlock(&philo -> mut_nb_meals_had);
}

int	eat(t_philo *philo)
{
	if (take_forks(philo))
		return (1);
	set_philo_state(philo, EATING);
	print_msg(philo -> data, philo -> id, EAT);
	update_last_meal_time(philo);
	wait_for_eating(philo -> data);
	update_meals_had(philo);
	drop_forks(philo);
	return (0);
}
