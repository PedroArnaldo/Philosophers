#include "../includes/philo.h"

int init_info(t_info *data, int argc, char **argv)
{
	
    if(argc >= 5 && argc <= 6)
    {
		data->num_of_philo = ft_atoi(argv[1]);
		data->time_to_die = ft_atoi(argv[2]);
		data->time_to_eat = ft_atoi(argv[3]);
		data->time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			data->num_times_must_eat = ft_atoi(argv[5]);
		return (1);
    }
    else
		return (0);
}
