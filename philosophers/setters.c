/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agadkari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:01:02 by agadkari          #+#    #+#             */
/*   Updated: 2024/03/20 15:01:04 by agadkari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_keep_iter(t_data *data, bool state)
{
	pthread_mutex_lock(&data -> mut_keep_iter);
	data -> keep_iterating = state;
	pthread_mutex_unlock(&data -> mut_keep_iter);
}

void	set_philo_state(t_philo *philo, t_state state)
{
	pthread_mutex_lock(&philo -> mut_state);
	if (philo -> state != DEAD)
		philo -> state = state;
	pthread_mutex_unlock(&philo -> mut_state);
}
