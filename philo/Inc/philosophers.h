/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rode-lim <rode-lim@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 19:13:54 by rode-lim          #+#    #+#             */
/*   Updated: 2024/09/16 15:25:29 by rode-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

//	input_err
# define ERROR_1 "Invalid number of arguments\n"
# define ERROR_2 "Invalid input of value\n"

//	pthread_err
# define TH_ERR "ERROR WHILE CREATING THREADS"
# define JOIN_ERR "ERROR WHILE JOINING THREADS"
# define INIT_ERR_1 "ERROR WHILE INIT FORKS"

//	time_err
# define TIME_ERR "UNABLE TO RETRIVE UTC"

//	philo_msg
# define TAKE_FORK "has taken a fork"
# define THINKING "is thinking"
# define SLEEPING "is sleeping"
# define EATING "is eating"
# define DIED "died"

typedef struct s_philo	t_philo;

typedef struct s_data
{
	pthread_t		observer;
	int				dead_flag;
	int				philos_num;
	time_t			start_time;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	int				num_times_to_eat;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	t_philo			*philosopher;
}					t_data;

struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	time_t			last_meal;
	int				*dead;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*meal_lock;
	pthread_mutex_t	*write_lock;
	t_data			*data;
};

//error_check.c
int		check_content(char *argv);
int		check_all_args(char **argv);
void	message(t_philo *philo, int id, char *str);

//init_threads.c
int		create_thread(t_data *data, pthread_mutex_t *forks);

//init.c
void	init_philos(t_philo *philo, t_data *data, pthread_mutex_t *forks);
void	init_forks(pthread_mutex_t *forks, int philo_num);
void	init_data(t_data *data, t_philo *philos, char **argv);

//monitor.c
void	*monitor(void *empty);
int		did_all_eat(t_philo *philos, t_data *data);
int		check_dead(t_philo *philos, t_data *data);
int		kill_philo(t_philo *philo, size_t time_to_die);

//routine.c
void	thinking(t_philo *philo);
void	sleeping(t_philo *philo, t_data *data);
void	eating(t_philo *philo, t_data *data);
int		is_dead(t_philo *philo);
void	*routine(void *empty);
void	ft_cleanse(t_philo *philo, t_data *data);

//utils.c
time_t	get_current_time(void);
int	ft_usleep(time_t milliseconds);
int		ft_atoi(const char *nptr);
void	destroy_mutex(t_data *data, pthread_mutex_t *forks, char *message);

#endif