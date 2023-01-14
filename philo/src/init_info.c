#include "../includes/philo.h"

int init_info(t_info *info, int argc, char **argv)
{
    if(argc >= 5 && argc <= 6)
    {
		info->num_of_philo = ft_atoi(argv[1]);
		info->time_to_die = ft_atoi(argv[2]);
		info->time_to_eat = ft_atoi(argv[3]);
		info->time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			info->num_times_must_eat = ft_atoi(argv[5]);
		return (1);
    }
    else
		return (0);
}
