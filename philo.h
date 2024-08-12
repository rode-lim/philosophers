#ifdef PHILO_H
#define PHILO_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <limits.h>

typedef struct	s_philo
{
	int	id;
	int	last_eat;
	int	is_eating;
	int	is_sleeping;
	int	is_thinking;
	int	is_dead;
	int	is_full;
	int	eat_count;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
	pthread_mutex_t	can_die;
}	t_philo;

typedef struct	s_general
{
	int	helper;
	int	philos_nbr;
	int	die_time;
	int	eat_time;
	int	sleep_time;
	int	must_eat;
	int	day_time;
	int	is_dead;
	int	philo_full;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	helper_mutex;
	t_philo	*philo;
}	t_general;

#endif