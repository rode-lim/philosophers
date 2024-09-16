/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rode-lim <rode-lim@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 19:14:04 by rode-lim          #+#    #+#             */
/*   Updated: 2024/09/13 19:14:05 by rode-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/philosophers.h"

int	check_content(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] != '\0')
	{
		if (argv[i] < '0' || argv[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

/*Function that checks if all the arguments are valid*/
int	check_all_args(char **argv)
{
	if ((ft_atoi(argv[1]) < 0 || ft_atoi(argv[1]) > 250) || 
		check_content(argv[2]) == 1)
		return (write(2, ERROR_2, 23), 1);
	if ((ft_atoi(argv[2]) < 0) || check_content(argv[2]) == 1)
		return (write(2, ERROR_2, 23), 1);
	if (ft_atoi(argv[3]) <= 0 || check_content(argv[3]) == 1)
		return (write(2, ERROR_2, 23), 1);
	if (ft_atoi(argv[4]) <= 0 || check_content(argv[4]) == 1)
		return (write(2, ERROR_2, 23), 1);
	if (argv[5] && (ft_atoi(argv[5]) < 0 || check_content(argv[5]) == 1))
		return (write(2, ERROR_2, 23), 1);
	return (0);
}

/*Function to print the specific message for the philosopher action*/
void	message(t_philo *philo, int id, char *str)
{
	size_t	time;

	pthread_mutex_lock(philo->write_lock);
	time = get_current_time() - philo->data->start_time;
	if (!is_dead(philo))
		printf("%zu %d %s\n", time, id, str);
	pthread_mutex_unlock(philo->write_lock);
}
