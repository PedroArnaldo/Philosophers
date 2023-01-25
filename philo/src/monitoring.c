/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:16:05 by parnaldo          #+#    #+#             */
/*   Updated: 2023/01/24 23:52:15 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	is_dead(t_philo *philo)
{
	int	someone_dead;

	pthread_mutex_lock(&philo->data->check_data);
	someone_dead = philo->data->someone_dead;
	pthread_mutex_unlock(&philo->data->check_data);
	if (someone_dead)
		return (1);
	if (time_now(philo) - philo->last_meals > philo->data->time_to_die)
	{
		pthread_mutex_lock(&philo->check);
		pthread_mutex_lock(&philo->stop);
		pthread_mutex_lock(&philo->data->check_data);
		philo->data->someone_dead = 1;
		pthread_mutex_unlock(&philo->data->check_data);
		pthread_mutex_unlock(&philo->stop);
		pthread_mutex_lock(&philo->data->print);
		if (!(philo->data->satisfied == philo->data->num_of_philo))
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
	pthread_mutex_lock(&philo->check);
	if (philo->data->someone_dead || check_full(philo))
	{
		pthread_mutex_unlock(&philo->check);
		return (1);
	}
	else
	{
		pthread_mutex_unlock(&philo->check);
		return (0);
	}
}

void	drop_fork(t_philo *philo)
{
	if (philo->use_fl && philo->use_fl != -1)
		pthread_mutex_unlock(&philo->data->all_forks[philo->fork_left]);
	if (philo->use_fr && philo->use_fr != -1)
		pthread_mutex_unlock(&philo->data->all_forks[philo->fork_right]);
}
