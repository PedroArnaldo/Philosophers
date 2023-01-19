/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:26:30 by parnaldo          #+#    #+#             */
/*   Updated: 2023/01/19 18:35:00 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_info data;
	t_philo *philo;
	int i;

	i = -1;
	memset(&data, 0, sizeof(data));
	memset(&philo, 0, sizeof(philo));
	if(!check_args(ac, av))
	{
		printf("Error\n");
		return (0);
	}
	philo = init_info(&data, philo, ac, av);
	if(philo)
	{
		data.time_start = time_now();
		while(++i < data.num_of_philo)
		{
			philo[i].last_meals = time_now();
			pthread_create(&philo[i].thread, NULL, &routines, &philo[i]);
		}
		i = -1;
		while (++i < data.num_of_philo)
			pthread_join(philo[i].thread, NULL);
	}
	return (0);
}
