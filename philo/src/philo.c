/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:26:30 by parnaldo          #+#    #+#             */
/*   Updated: 2023/01/22 17:14:35 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	one_philo(t_philo *philo)
{
	pthread_create(&philo[0].thread, NULL, &routines, &philo[0]);
	pthread_join(philo[0].thread, NULL);
}

int	main(int ac, char **av)
{
	t_info	data;
	t_philo	*philo;
	int		i;

	i = -1;
	memset(&data, 0, sizeof(data));
	memset(&philo, 0, sizeof(philo));
	if (!check_args(ac, av))
	{
		printf("Error\n");
		return (0);
	}
	philo = init_info(&data, philo, ac, av);
	if (philo)
	{
		data.time_start = get_time();
		if (data.num_of_philo != 1)
		{
			while (++i < data.num_of_philo)
				pthread_create(&philo[i].thread, NULL, &routines, &philo[i]);
			i = -1;
			while (++i < data.num_of_philo)
				pthread_join(philo[i].thread, NULL);
		}
		else
			one_philo(&philo[0]);
	}
	return (0);
}
