/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rode-lim <rode-lim@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 19:14:38 by rode-lim          #+#    #+#             */
/*   Updated: 2024/09/18 11:47:12 by rode-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/philosophers.h"

void	thinking(t_philo *philo)
{
	message(philo, philo->id, THINKING);
	if (philo->data->time_to_eat >= philo->data->time_to_sleep)
		ft_usleep((philo->data->time_to_eat * 2) \
			- philo->data->time_to_sleep);
}

void	sleeping(t_philo *philo, t_data *data)
{
	message(philo, philo->id, SLEEPING);
	ft_usleep(data->time_to_sleep);
}

void	eating(t_philo *philo, t_data *data)
{
	if (data->philos_num == 1)
	{
		pthread_mutex_lock(philo->right_fork);
		ft_usleep(data->time_to_die);
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
	if (philo->id % 2 != 0) 
	{
		pthread_mutex_lock(philo->left_fork);
		message(philo, philo->id, TAKE_FORK);
		pthread_mutex_lock(philo->right_fork);
		message(philo, philo->id, TAKE_FORK);
	}
	else 
	{
		pthread_mutex_lock(philo->right_fork);
		message(philo, philo->id, TAKE_FORK);
		pthread_mutex_lock(philo->left_fork);
		message(philo, philo->id, TAKE_FORK);
	}
	ft_cleanse(philo, data);
}

int	is_dead(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&data->dead_lock);
	if (*philo->dead == 1)
	{
		pthread_mutex_unlock(&data->dead_lock);
		return (1);
	}
	pthread_mutex_unlock(&data->dead_lock);
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (!is_dead(philo))
	{
		eating(philo, data);
		sleeping(philo, data);
		if (data->philos_num % 2 != 0)
			thinking(philo);
	}
	return (arg);
}
