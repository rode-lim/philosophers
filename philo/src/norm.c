#include "../Inc/philosophers.h"

void	ft_cleanse(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(philo->meal_lock);
	philo->eating = 1;
	message(philo, philo->id, EATING);
	philo->last_meal = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	ft_usleep(data->time_to_eat);
	philo->eating = 0;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}
