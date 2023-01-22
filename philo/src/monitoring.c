/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:16:05 by parnaldo          #+#    #+#             */
/*   Updated: 2023/01/22 19:36:25 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	is_dead(t_philo *philo)
{
	if (philo->data->someone_dead)
		return (1);
	if (time_now(philo) - philo->last_meals > philo->data->time_to_die)
	{
		printf("%lums %d died\n", time_now(philo), philo->id);
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
