/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rode-lim <rode-lim@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 19:14:25 by rode-lim          #+#    #+#             */
/*   Updated: 2024/09/13 19:14:26 by rode-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/philosophers.h"

int	main(int argc, char **argv)
{
	t_data			data;
	t_philo			philos[250];
	pthread_mutex_t	forks[250];

	if (argc < 5 || argc > 6)
	{
		printf(ERROR_1);
		return (1);
	}
	if (check_all_args(argv) == 1)
		return (1);
	init_data(&data, philos, argv);
	init_forks(forks, ft_atoi(argv[1]));
	init_philos(philos, &data, forks);
	create_thread(&data, forks);
	destroy_mutex(&data, forks, NULL);
	return (0);
}
