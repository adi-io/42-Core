/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agadkari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:00:27 by agadkari          #+#    #+#             */
/*   Updated: 2024/03/20 15:12:29 by agadkari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *) data;
	update_last_meal_time(philo);
	if (philo -> id % 2 == 0)
		ft_usleep(philo -> data -> eat_time - 10);
	while (get_philo_state(philo) != DEAD)
	{
		if (eat(philo))
			break ;
		if (get_philo_state(philo) == DEAD)
			break ;
		if (ft_sleep(philo))
			break ;
		if (get_philo_state(philo) == DEAD)
			break ;
		if (ft_think(philo))
			break ;
	}
	return (NULL);
}
