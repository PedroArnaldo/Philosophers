/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:16:05 by parnaldo          #+#    #+#             */
/*   Updated: 2023/01/23 13:37:45 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->check);
	if (philo->data->someone_dead)
	{
		pthread_mutex_unlock(&philo->check);
		return (1);
	}
	pthread_mutex_unlock(&philo->check);
	if (time_now(philo) - philo->last_meals > philo->data->time_to_die)
	{
		pthread_mutex_lock(&philo->check);
		philo->data->someone_dead = 1;
		pthread_mutex_lock(&philo->data->print);
			printf("%lums\t%d\t died\n", time_now(philo), philo->id);
		pthread_mutex_unlock(&philo->data->print);
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
