int	main()
{
	number_of_philosophers;
	time_to_die;
	time_to_eat;
	time_to_sleep;
	umber_of_times_each_philosopher_must_eat;
}

This will mostly be all int since they are numbers.
I will have to make a checker that checks everything.
The number of philosophers is the same as the number of forks.

Meaning 3 philo = 3 forks

Each philosopher needs 2 forks to eat.
Meaning the best solution is when 1 is sleeping their fork stays on the table.

A function that makes it so the philosopher that goes to sleep leaves his fork available is needed.

A function that checks that when everyone is awake give priority to the first philosopher to eat and go to sleep.

Make it so when a philosopher wakes up he thinks.

Make a function (bool) that when is set on (death) the program stops.

bool	ft_is_dead(int time_to_die)
{
	if(time_to_die == 0)
	{
		ft_printf("dead bro D:");
		break;
	}
}

dont	forget(to keep)
{
	open by doing;
	while(1)
	{
		This way the program won't go down.
	}
}
