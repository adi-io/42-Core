/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agadkari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:58:37 by agadkari          #+#    #+#             */
/*   Updated: 2024/03/20 14:58:41 by agadkari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_right_fork(t_philo *philo)
{
	if (philo_dead(philo))
		return (1);
	pthread_mutex_lock(philo -> right_f);
	print_msg(philo -> data, philo -> id, TAKE_FORKS);
	return (0);
}

int	take_left_fork(t_philo *philo)
{
	if (philo_dead(philo))
		return (1);
	pthread_mutex_lock(philo -> left_f);
	print_msg(philo -> data, philo -> id, TAKE_FORKS);
	return (0);
}

void	drop_forks(t_philo *philo)
{
	drop_right_fork(philo);
	drop_left_fork(philo);
}

void	drop_left_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo -> left_f);
}

void	drop_right_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo -> right_f);
}
