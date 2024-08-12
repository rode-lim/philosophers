#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	check_is_number(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
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
	if((ac == 5 || ac == 6) && check_is_number(av))
		return (1);
	else
	{
		write(2, "Error: invalid arguments\n", 26);
		return (0);
	}
}

int	main(int ac, char **av)
{
	t_general	general;

	if (valid_arguments(ac, av))
	{}
}
