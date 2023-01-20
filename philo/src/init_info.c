/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:44:30 by parnaldo          #+#    #+#             */
/*   Updated: 2023/01/19 23:06:16 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_philo	*init_info(t_info *data, t_philo *philo, int argc, char **argv)
{
	int i;
	unsigned long ms;

	i = 0;
    if(argc >= 5 && argc <= 6)
    {
		data->num_of_philo = ft_atoi(argv[1]);
		data->time_to_die = ft_atoi(argv[2]);
		data->time_to_eat = ft_atoi(argv[3]);
		data->time_to_sleep = ft_atoi(argv[4]);
		data->satisfied = 0;
		if (argc == 6)
			data->num_times_must_eat = ft_atoi(argv[5]);
		data->all_forks = malloc(sizeof(pthread_mutex_t) * data->num_of_philo); 
		philo = malloc(sizeof(t_philo) * data->num_of_philo);
		data->philo = philo;
		ms = time_now();
		while (i < data->num_of_philo)
		{
			philo[i].id = i + 1;
			philo[i].fork_left = i;
			philo[i].fork_right = (i+1) % data->num_of_philo;
			philo[i].data = data;
			philo[i].last_meals = ms;
			philo[i].ate_times = 0;
			pthread_mutex_init(&philo[i].stop, NULL);
			pthread_mutex_init(&philo[i].check, NULL);		
			i++;
		}
		pthread_mutex_init(&data->print, NULL);
		return (philo);
    }
    else
		return (0);
}


