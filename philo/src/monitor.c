/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rode-lim <rode-lim@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 19:14:32 by rode-lim          #+#    #+#             */
/*   Updated: 2024/09/13 19:14:33 by rode-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/philosophers.h"

int	kill_philo(t_philo *philo, size_t time_to_die)
{
	size_t	time_since_last_meal;
	int		is_dead;

	pthread_mutex_lock(philo->meal_lock);
	time_since_last_meal = get_current_time() - philo->last_meal;
	is_dead = ((time_since_last_meal >= time_to_die) && (philo->eating == 0));
	pthread_mutex_unlock(philo->meal_lock);
	return (is_dead);
}

int	check_dead(t_philo *philos, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philos_num)
	{
		if (kill_philo(&philos[i], data->time_to_die))
		{
			message(&philos[i], philos[i].id, DIED);
			pthread_mutex_lock(&data->dead_lock);
			data->dead_flag = 1;
			pthread_mutex_unlock(&data->dead_lock);
			return (1);
		}
		i++;
	}
	return (0);
}

int	did_all_eat(t_philo *philos, t_data *data)
{
	int	i;
	int	finished_eating;

	i = 0;
	finished_eating = 0;
	if (data->num_times_to_eat == -1)
		return (0);
	while (i < data->philos_num)
	{
		pthread_mutex_lock(philos[i].meal_lock);
		if (philos[i].meals_eaten >= data->num_times_to_eat)
			finished_eating++;
		pthread_mutex_unlock(philos[i].meal_lock);
		i++;
	}
	if (finished_eating == data->philos_num)
	{
		pthread_mutex_lock(&data->dead_lock);
		*philos->dead = 1;
		pthread_mutex_unlock(&data->dead_lock);
		return (1);
	}
	return (0);
}

void	*monitor(void *arg)
{
	t_philo	*philos;
	t_data	*data;

	philos = (t_philo *)arg;
	data = philos->data;
	while (1)
	{
		if (check_dead(philos, data) == 1 || did_all_eat(philos, data) == 1)
			break ;
	}
	return (arg);
}
