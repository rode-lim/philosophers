/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rode-lim <rode-lim@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 19:14:17 by rode-lim          #+#    #+#             */
/*   Updated: 2024/09/13 19:14:18 by rode-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/philosophers.h"

void	init_data(t_data *data, t_philo *philos, char **argv)
{
	data->philosopher = philos;
	data->start_time = get_current_time();
	data->philos_num = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5] != NULL)
		data->num_times_to_eat = ft_atoi(argv[5]);
	else
		data->num_times_to_eat = -1;
	data->dead_flag = 0;
	pthread_mutex_init(&data->meal_lock, NULL);
	pthread_mutex_init(&data->write_lock, NULL);
	pthread_mutex_init(&data->dead_lock, NULL);
}

void	init_forks(pthread_mutex_t *forks, int philo_num)
{
	int	i;

	i = 0;
	while (i < philo_num)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	init_philos(t_philo *philo, t_data *data, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < data->philos_num)
	{
		philo[i].id = i + 1;
		philo[i].eating = 0;
		philo[i].meals_eaten = 0;
		philo[i].last_meal = data->start_time;
		philo[i].write_lock = &data->write_lock;
		philo[i].meal_lock = &data->meal_lock;
		philo[i].dead = &data->dead_flag;
		philo[i].data = data;
		philo[i].left_fork = &forks[(i + data->philos_num - 1) \
			% data->philos_num];
		philo[i].right_fork = &forks[i];
		i++;
	}
}
