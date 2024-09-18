/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rode-lim <rode-lim@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 19:14:44 by rode-lim          #+#    #+#             */
/*   Updated: 2024/09/18 12:00:59 by rode-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/philosophers.h"

// Gets the current time in milliseconds.
time_t	get_current_time(void)
{
	struct timeval		tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	ft_usleep(time_t milliseconds)
{
	time_t	wake_up;

	wake_up = get_current_time() + milliseconds;
	while (get_current_time() < wake_up)
		usleep(100);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int				i;
	int				res;
	int				a;
	unsigned int	nb;

	res = 0;
	a = 1;
	i = 0;
	nb = 0;
	while ((nptr[i] == ' ') || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			a = -a;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - 48);
		i++;
	}
	res = nb * a;
	return (res);
}

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	destroy_mutex(t_data *data, pthread_mutex_t *forks, char *message)
{
	int	i;

	i = 0;
	if (message)
	{
		write(2, message, ft_strlen(message));
		write(2, "\n", 1);
	}
	pthread_mutex_destroy(&data->meal_lock);
	pthread_mutex_destroy(&data->write_lock);
	pthread_mutex_destroy(&data->dead_lock);
	while (i < data->philos_num)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}
