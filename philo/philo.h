/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rode-lim <rode-lim@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:22:24 by rode-lim          #+#    #+#             */
/*   Updated: 2024/09/13 16:30:17 by rode-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

typedef struct s_philo
{
	int				id;
	int				last_eat;
	int				is_eating;
	int				is_sleeping;
	int				is_thinking;
	int				is_dead;
	int				is_full;
	int				eat_count;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
	pthread_mutex_t	can_die;
}	t_philo;

typedef struct s_general
{
	int				helper;
	int				philos_nbr;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				must_eat;
	int				day_time;
	int				is_dead;
	int				philo_full;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	helper_mutex;
	t_philo			*philo;
}	t_general;

/*-------------------------check_arguents.c------------------------*/

int		ft_isdigit(int i);
int		ftisdigit(char **argv);
int		ft_atoi(char *str);
int		valid_arguments(int ac, char **av);
/*__________________________________________________________________*/

/*------------------------------init.c-----------------------------*/

int		get_time(void);
int		check_numbers(t_general *philo);
void	start_threads(t_general *general);
int		init_arguments(t_general *philo, int ac, char **av);
void	init_philos(t_general *general);
/*__________________________________________________________________*/

/*-----------------------------philo_status.c-----------------------------*/

void	philo_take_fork(t_general *general, int id);
void	philo_sleep(t_general *general, int id);
void	philo_think(t_general *general, int id);
void	philo_eat(t_general *general, int id);
int		philo_is_dead(t_general *general, int id);
/*__________________________________________________________________*/

/*-----------------------------routine.c---------------------------*/

void	supervisor(void	*philo_ptr);
void	*routine(void *arg);
void	print_status(t_general *general, int id, char c);
void	plswork(t_general *general, int id);
/*__________________________________________________________________*/

#endif