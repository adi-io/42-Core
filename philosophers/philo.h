/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agadkari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:58:14 by agadkari          #+#    #+#             */
/*   Updated: 2024/03/20 15:58:43 by agadkari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <stdint.h>
# include <stdbool.h>

# define WRONG_INPUT 1
# define MALLOC_ERROR 2

# define TAKE_FORKS "has taken a fork"
# define THINK "is thinking"
# define SLEEP "is sleeping"
# define EAT "is eating"
# define DIED "died"

typedef enum e_philo_state
{
	EATING = 0,
	SLEEPING = 1,
	THINKING = 2,
	DEAD = 3,
	FULL = 4,
	IDLE = 5
}	t_state;

struct	s_data;

typedef struct s_philo
{
	int				id;
	int				nb_meals_had;
	struct s_data	*data;
	t_state			state;
	pthread_mutex_t	*left_f;
	pthread_mutex_t	*right_f;
	pthread_mutex_t	mut_state;
	pthread_mutex_t	mut_nb_meals_had;
	pthread_mutex_t	mut_last_eat_time;
	u_int64_t		last_eat_time;
}	t_philo;

typedef struct s_data
{
	int				nb_philos;
	int				nb_meals;
	int				nb_full_p;
	bool			keep_iterating;
	u_int64_t		eat_time;
	u_int64_t		die_time;
	u_int64_t		sleep_time;
	u_int64_t		start_time;
	pthread_mutex_t	mut_eat_time;
	pthread_mutex_t	mut_die_time;
	pthread_mutex_t	mut_sleep_time;
	pthread_mutex_t	mut_print;
	pthread_mutex_t	mut_nb_philos;
	pthread_mutex_t	mut_keep_iter;
	pthread_mutex_t	mut_start_time;
	pthread_t		monit_all_alive;
	pthread_t		monit_all_full;
	pthread_t		*philo_ths;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}	t_data;

int			eat(t_philo *philo);
int			take_forks(t_philo *philo);
void		update_last_meal_time(t_philo *philo);
void		wait_for_eating(t_data *data);
void		update_meals_had(t_philo *philo);
void		drop_right_fork(t_philo *philo);
void		drop_left_fork(t_philo *philo);
void		drop_forks(t_philo *philo);
int			take_right_fork(t_philo *philo);
int			take_left_fork(t_philo *philo);
bool		get_keep_iter(t_data *data);
int			get_nb_meals_had(t_philo *philo);
t_state		get_philo_state(t_philo *philo);
int			is_philo_dead(t_philo *philo);
int			get_nb_philos(t_data *data);
void		*all_alive(void *arg);
void		*all_full(void *arg);
void		terminate_philos(t_data *data);
bool		is_philo_full(t_data *data, t_philo *philo);
int			philo_dead(t_philo *philo);
int			philo_init(t_data *data, int argc, char **argv);
int			philo_malloc(t_data *data);
int			philo_create(t_data *data);
int			fork_create(t_data *data);
int			handle_one_philo(t_philo *philo);
void		sweaper(t_data *data);
void		print_mut(t_data *data, char *msg);
void		print_msg(t_data *data, int id, char *msg);
bool		nb_meals_option(t_data *data);
int			ft_atoi(const char *str);
void		ft_usleep(uint64_t sleep_time);
int			ft_sleep(t_philo *philo);
int			ft_think(t_philo *philo);
void		set_philo_state(t_philo *philo, t_state state);
void		set_keep_iter(t_data *data, bool state);
void		*routine(void *data);

uint64_t	get_last_meal_time(t_philo *philo);
uint64_t	get_start_time(t_data *data);
uint64_t	get_sleep_time(t_data *data);
uint64_t	get_die_time(t_data *data);
uint64_t	get_eat_time(t_data *data);
uint64_t	get_time(void);

#endif
