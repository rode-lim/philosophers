/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rode-lim <rode-lim@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:23:45 by rode-lim          #+#    #+#             */
/*   Updated: 2024/09/13 16:23:46 by rode-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(t_general *general, int id, char c)
{
	pthread_mutex_lock(&(*general).print);
	if (c == 'e' && !(*general).is_dead)
		printf("%d ms %d is eating\n", get_time() - (*general).day_time,
			(*general).philo[id].id);
	else if (c == 'f' && !(*general).is_dead)
		printf("%d ms %d has taken a fork \n", get_time() - (*general).day_time,
			(*general).philo[id].id);
	else if (c == 't' && !(*general).is_dead)
		printf("%d ms %d is thinking\n", get_time() - (*general).day_time,
			(*general).philo[id].id);
	else if (c == 's' && !(*general).is_dead)
		printf("%d ms %d is sleeping\n", get_time() - (*general).day_time,
			(*general).philo[id].id);
	pthread_mutex_unlock(&(*general).print);
}

void	plswork(t_general *general, int id)
{
	philo_take_fork(general, id);
	philo_eat(general, id);
	philo_sleep(general, id);
	philo_think(general, id);
	pthread_mutex_lock(&(*general).print);
	usleep(100);
}

void	one_philo(t_general *general, int id)
{
	print_status(general, id, 'f');
	(*general).philo[id].last_eat = get_time();
	usleep((*general).die_time * 1000);
	philo_is_dead(general, id);
}

void	*routine(void *arg)
{
	t_general	*general;
	int			id;

	general = (t_general *)arg;
	pthread_mutex_lock(&(*general).helper_mutex);
	id = (*general).helper;
	(*general).helper++;
	pthread_mutex_unlock(&(*general).helper_mutex);
	if ((*general).philos_nbr == 1)
		one_philo(general, id);
	pthread_mutex_lock(&(*general).print);
	while (!(*general).is_dead)
		plswork(general, id);
	pthread_mutex_unlock(&(*general).print);
	return (NULL);
}
