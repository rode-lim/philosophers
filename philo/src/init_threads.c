/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rode-lim <rode-lim@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 19:14:11 by rode-lim          #+#    #+#             */
/*   Updated: 2024/09/13 19:14:12 by rode-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/philosophers.h"

//Criar um observer para monitorizar o programa inteiro
int	create_thread(t_data *data, pthread_mutex_t *forks)
{
	int			i;
	pthread_t	god;

	i = 0;
	if (pthread_create(&god, NULL, &monitor, data->philosopher) != 0)
		destroy_mutex(data, forks, TH_ERR);
	while (i < data->philos_num)
	{
		if (pthread_create(&data->philosopher[i].thread, NULL, &routine, 
				&data->philosopher[i]) != 0)
			destroy_mutex(data, forks, TH_ERR);
		i++;
	}
	i = 0;
	if (pthread_join(god, NULL) != 0)
		destroy_mutex(data, forks, JOIN_ERR);
	while (i < data->philos_num)
	{
		if (pthread_join(data->philosopher[i].thread, NULL) != 0)
			destroy_mutex(data, forks, JOIN_ERR);
		i++;
	}
	return (0);
}
