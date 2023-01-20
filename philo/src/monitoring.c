/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:16:05 by parnaldo          #+#    #+#             */
/*   Updated: 2023/01/20 09:31:05 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	monitoring(t_philo *philo)
{
	unsigned long ms;
	int result;

	pthread_mutex_lock(&philo->stop);
	ms = time_now() - philo->last_meals;
	if (ms > philo->data->time_to_die && philo->data->someone_dead == 0)
	{
		printf("%lums\t%d\t %s\n", time_now() - philo->data->time_start, philo->id, "died");
	    result = 1;
	}
	else if(philo->data->someone_dead)
		result = 1;
	result = 0;
	pthread_mutex_unlock(&philo->stop);
	return (result);
}
