/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:16:05 by parnaldo          #+#    #+#             */
/*   Updated: 2023/01/22 17:04:34 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/* int	monitoring(t_philo *philo)
{
	unsigned long	ms;
	int				result;

	pthread_mutex_lock(&philo->stop);
	ms = time_now() - philo->last_meals;
	if (ms > philo->data->time_to_die && philo->data->someone_dead == 0)
	{
		printf("%lums %d %s\n", \
		time_now() - philo->data->time_start, philo->id, "died");
		philo->data->someone_dead = 1;
		result = 1;
	}
	else if (philo->data->someone_dead)
		result = 1;
	result = 0;
	pthread_mutex_unlock(&philo->stop);
	return (result);
} */

int	is_dead(t_philo *philo)
{
	if (philo->data->someone_dead)
		return (1);
	if (philo->last_meals > philo->data->time_to_die)
	{
		pthread_mutex_lock(&philo->check);
		philo->data->someone_dead = 1;
		pthread_mutex_unlock(&philo->check);
		return (1);
	}
	else
		return (0);
}

int	check_full(t_philo *philo)
{
	if (philo->meals == philo->data->num_times_must_eat)
		return (1);
	else
		return (0);
}

int	check_stop(t_philo *philo)
{
	if (philo->data->someone_dead || check_full(philo))
		return (1);
	else
		return (0);
}
