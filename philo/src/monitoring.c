/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:16:05 by parnaldo          #+#    #+#             */
/*   Updated: 2023/01/19 18:07:09 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	did_someone_die(t_philo *philo)
{
	unsigned long  ms;
	int i;

	pthread_mutex_lock(&philo->stop);
	i = 0;
	ms = time_now() - philo->last_meals;
	if (philo->data->is_dead_philo != 1)
	{
		ms = time_now() - philo->last_meals;
		if(ms > philo->data->time_to_die)
		{
			ms = time_now() - philo->data->time_start;
			print_routinet(ms, philo, "died");
			philo->data->is_dead_philo = 1;
			i = 1;
		}
		else
			i = 0;
	}
	pthread_mutex_unlock(&philo->stop);
	return (i);
}
