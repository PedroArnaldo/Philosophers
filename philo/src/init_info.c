#include "../includes/philo.h"

t_philo	*init_info(t_info *data, t_philo *philo, int argc, char **argv)
{
	int i;

	i = 0;
    if(argc >= 5 && argc <= 6)
    {
		data->num_of_philo = ft_atoi(argv[1]);
		data->time_to_die = ft_atoi(argv[2]);
		data->time_to_eat = ft_atoi(argv[3]);
		data->time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			data->num_times_must_eat = ft_atoi(argv[5]);
		data->all_forks = malloc(sizeof(pthread_mutex_t) * data->num_of_philo); 
		philo = malloc(sizeof(t_philo) * data->num_of_philo);
		data->philo = philo;	
		while (i < data->num_of_philo)
		{
			philo[i].id = i + 1;
			philo[i].fork_left = i;
			philo[i].fork_right = i+1;
			philo[i].data = data;
			philo[i].use_fork = 0;
			i++;
		}
		pthread_mutex_init(&data->print, NULL);
		pthread_mutex_init(&philo->stop, NULL);		
		return (philo);
    }
    else
		return (0);
}


