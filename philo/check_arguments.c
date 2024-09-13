/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rode-lim <rode-lim@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:27:04 by rode-lim          #+#    #+#             */
/*   Updated: 2024/09/13 16:28:52 by rode-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int i)
{
	if (i >= '0' && i <= '9')
		return (1);
	return (0);
}

int	ftisdigit(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (ft_isdigit(argv[i][j]) == 1)
				j++;
			else if (argv[i][j] == '-' || argv[i][j] == ' ')
				return (0);
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	neg;
	int	res;

	i = 0;
	res = 0;
	neg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		res = (str[i] - '0') + (res * 10);
		i++;
	}
	return (res * neg);
}

int	check_is_numbers(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i] != NULL)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if (ft_isdigit(av[i][j]) == 1)
				j++;
			else if (av[i][j] == '-' || av[i][j] == ' ')
				return (0);
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	valid_arguments(int ac, char **av)
{
	if ((ac == 5 || ac == 6) && check_is_numbers(av))
		return (1);
	else
		return (0);
}
