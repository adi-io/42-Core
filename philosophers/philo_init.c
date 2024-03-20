/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agadkari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:00:17 by agadkari          #+#    #+#             */
/*   Updated: 2024/03/20 15:11:55 by agadkari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	fork_create(t_data *data)
{
	int		i;
	int		nb;
	t_philo	*philos;

	i = -1;
	nb = get_nb_philos(data);
	philos = data -> philos;
	while (++i < nb)
	{
		pthread_mutex_init(&data -> forks[i], NULL);
	}
	philos[0].right_f = &data -> forks[0];
	philos[0].left_f = &data -> forks[nb - 1];
	i = 1;
	while (i < nb)
	{
		philos[i].right_f = &data -> forks[i - 1];
		philos[i].left_f = &data -> forks[i];
		i++;
	}
	return (0);
}

int	philo_create(t_data *data)
{
	int		i;
	int		nb;
	t_philo	*philos;

	i = -1;
	nb = get_nb_philos(data);
	philos = data ->philos;
	while (++i < nb)
	{
		philos[i].id = i + 1;
		philos[i].nb_meals_had = 0;
		philos[i].data = data;
		philos[i].state = IDLE;
		pthread_mutex_init(&philos[i].mut_state, NULL);
		pthread_mutex_init(&philos[i].mut_nb_meals_had, NULL);
		pthread_mutex_init(&philos[i].mut_last_eat_time, NULL);
		update_last_meal_time(&philos[i]);
	}
	return (0);
}

int	philo_malloc(t_data *data)
{
	int	nb;

	nb = get_nb_philos(data);
	data -> philos = malloc(sizeof(t_philo) * nb);
	if (!data -> philos)
		return (MALLOC_ERROR);
	data -> philo_ths = malloc(sizeof(pthread_t) * nb);
	if (!data -> philo_ths)
		return (MALLOC_ERROR);
	data -> forks = malloc(sizeof(pthread_mutex_t) * nb);
	if (!data -> forks)
		return (MALLOC_ERROR);
	return (0);
}

int	philo_init(t_data *data, int argc, char **argv)
{
	data -> nb_philos = ft_atoi(argv[1]);
	data -> nb_meals = 1;
	if (argc == 6)
		data -> nb_meals = ft_atoi(argv[5]);
	data -> nb_full_p = 0;
	data -> keep_iterating = true;
	data -> eat_time = (uint64_t)ft_atoi(argv[3]);
	data -> die_time = (uint64_t)ft_atoi(argv[2]);
	data -> sleep_time = (uint64_t)ft_atoi(argv[4]);
	pthread_mutex_init(&data -> mut_eat_time, NULL);
	pthread_mutex_init(&data -> mut_die_time, NULL);
	pthread_mutex_init(&data -> mut_sleep_time, NULL);
	pthread_mutex_init(&data -> mut_print, NULL);
	pthread_mutex_init(&data -> mut_nb_philos, NULL);
	pthread_mutex_init(&data -> mut_keep_iter, NULL);
	pthread_mutex_init(&data -> mut_start_time, NULL);
	return (philo_malloc(data));
}
