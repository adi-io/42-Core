/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agadkari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:00:01 by agadkari          #+#    #+#             */
/*   Updated: 2024/03/20 15:16:24 by agadkari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	checker(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (1);
	if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[1]) > 200)
		return (1);
	if (ft_atoi(argv[2]) < 60)
		return (1);
	if (ft_atoi(argv[3]) < 60 || ft_atoi(argv[4]) < 60)
		return (1);
	if (argc == 6 && ft_atoi(argv[5]) <= 0)
		return (1);
	return (0);
}

int	run_philo(t_data *data)
{
	int	i;
	int	nb;

	i = -1;
	nb = get_nb_philos(data);
	data -> start_time = get_time();
	while (++i < nb)
	{
		if (pthread_create(&data -> philo_ths[i],
				NULL, &routine, &data -> philos[i]))
			return (1);
	}
	if (pthread_create(&data ->monit_all_alive, NULL, &all_alive, data))
		return (1);
	if (nb_meals_option(data) == true && pthread_create(&data -> monit_all_full,
			NULL, &all_full, data))
		return (1);
	return (0);
}

int	join_threds(t_data *data)
{
	int	i;
	int	nb;

	i = -1;
	nb = get_nb_philos(data);
	if (pthread_join(data -> monit_all_alive, NULL))
		return (1);
	if (nb_meals_option(data) == true
		&& pthread_join(data -> monit_all_full, NULL))
		return (1);
	while (++i < nb)
	{
		if (pthread_join(data -> philo_ths[i], NULL))
			return (1);
	}
	return (0);
}

int	philoshoper(int argc, char **argv)
{
	t_data		data;

	if (philo_init(&data, argc, argv))
		return (1);
	philo_create(&data);
	fork_create(&data);
	run_philo(&data);
	join_threds(&data);
	sweaper(&data);
	return (0);
}

int	main(int argc, char **argv)
{
	if (checker(argc, argv))
		return (1);
	if (philoshoper(argc, argv))
		return (2);
	return (0);
}
