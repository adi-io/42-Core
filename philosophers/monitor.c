/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agadkari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:59:19 by agadkari          #+#    #+#             */
/*   Updated: 2024/03/20 15:22:09 by agadkari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_dead(t_philo *philo)
{
	uint64_t	result;

	result = get_time() - get_last_meal_time(philo);
	if ((result > get_die_time(philo -> data))
		&& get_philo_state(philo) != EATING)
		return (1);
	return (0);
}

bool	is_philo_full(t_data *data, t_philo *philo)
{
	bool	result;

	result = false;
	if (get_nb_meals_had(philo) >= data -> nb_meals)
		result = true;
	return (result);
}

void	terminate_philos(t_data *data)
{
	int		i;
	int		nb;
	t_philo	*philo;

	i = -1;
	nb = get_nb_philos(data);
	philo = data -> philos;
	while (++i < nb)
		set_philo_state(&philo[i], DEAD);
}

void	*all_full(void *arg)
{
	int		i;
	int		nb;
	t_data	*data;
	t_philo	*philo;

	data = (t_data *)arg;
	philo = data -> philos;
	i = -1;
	nb = get_nb_philos(data);
	while (++i < nb && get_keep_iter(data))
	{
		if (is_philo_full(data, &philo[i]) == false)
			i = -1;
	}
	if (get_keep_iter(data))
	{
		set_keep_iter(data, false);
		terminate_philos(data);
	}
	return (NULL);
}

void	*all_alive(void *arg)
{
	int		i;
	int		nb;
	t_data	*data;
	t_philo	*philo;

	data = (t_data *)arg;
	philo = data -> philos;
	i = -1;
	nb = get_nb_philos(data);
	while (++i < nb && get_keep_iter(data))
	{
		if (philo_dead(&philo[i])
			&& get_keep_iter(data))
		{
			print_msg(data, philo[i].id, DIED);
			set_keep_iter(data, false);
			terminate_philos(data);
		}
		if (i == (nb -1))
			i = -1;
		usleep(1000); //understand why this??
	}
	return (NULL);
}
