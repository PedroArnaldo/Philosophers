/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:44:30 by parnaldo          #+#    #+#             */
/*   Updated: 2023/01/22 16:46:46 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_philo	*init_info(t_info *data, t_philo *philo, int argc, char **argv)
{
	int				i;

	i = -1;
	if (argc >= 5 && argc <= 6)
	{
		data->num_of_philo = ft_atoi(argv[1]);
		data->time_to_die = ft_atoi(argv[2]);
		data->time_to_eat = ft_atoi(argv[3]);
		data->time_to_sleep = ft_atoi(argv[4]);
		data->satisfied = 0;
		data->someone_dead = 0;
		if (argc == 6)
			data->num_times_must_eat = ft_atoi(argv[5]);
		else
			data->num_times_must_eat = -1;
		data->all_forks = malloc(sizeof(pthread_mutex_t) * data->num_of_philo);
		philo = malloc(sizeof(t_philo) * data->num_of_philo);
		data->philo = philo;
		sleep(1);
		while (++i < data->num_of_philo)
		{
			philo[i].id = i + 1;
			philo[i].fork_left = i;
			philo[i].fork_right = (i + 1) % data->num_of_philo;
			philo[i].data = data;
			philo[i].use_fr = 0;
			philo[i].use_fl = 0;
			philo[i].last_meals = get_time();
			philo[i].meals = 0;
		}
		//printf("time_now philo 1 %lu \n",time_now(&philo[1]));
		init_mutex(philo);
		return (philo);
	}
	else
		return (NULL);
}

void	init_mutex(t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_init(&philo->data->print, NULL);
	while (i < philo->data->num_of_philo)
	{
		pthread_mutex_init(&philo[i].data->all_forks[i], NULL);
		pthread_mutex_init(&philo[i].stop, NULL);
		pthread_mutex_init(&philo[i].check, NULL);
		i++;
	}
}
