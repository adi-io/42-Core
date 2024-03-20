/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agadkari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:01:34 by agadkari          #+#    #+#             */
/*   Updated: 2024/03/20 15:01:37 by agadkari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	handle_one_philo(t_philo *philo)
{
	take_left_fork(philo);
	ft_usleep(get_die_time(philo -> data));
	set_philo_state(philo, DEAD);
	return (1);
}
