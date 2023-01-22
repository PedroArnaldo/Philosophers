/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:07:24 by parnaldo          #+#    #+#             */
/*   Updated: 2023/01/22 00:56:45 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->all_forks[philo->fork_right]);
	print_routinet(philo, "has taken a fork");
	pthread_mutex_lock(&philo->data->all_forks[philo->fork_left]);
	print_routinet(philo, "has taken a fork");
}

void	eat(t_philo *philo)
{
	philo->last_meals = time_now(philo);
	print_routinet(philo, "is eating");
	philo->meals++;
	pthread_mutex_lock(&philo->check);
	if (philo->meals == philo->data->num_times_must_eat)
		philo->data->satisfied++;
	pthread_mutex_unlock(&philo->check);
	smart_sleep(philo->data->time_to_eat, philo);
	pthread_mutex_unlock(&philo->data->all_forks[philo->fork_left]);
	pthread_mutex_unlock(&philo->data->all_forks[philo->fork_right]);
}

void	sleeping(t_philo *philo)
{
	print_routinet(philo, "is sleeping");
	smart_sleep(philo->data->time_to_sleep, philo);
}

void	think(t_philo *philo)
{
	print_routinet(philo, "is thinking");
}

void	*routines(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	if (philo->id % 2 == 0)
		usleep(philo->data->time_to_eat * 1000);
	while (42)
	{
		take_fork(philo);
		eat(philo);
		sleeping(philo);
		think(philo);
		if (philo->data->num_of_philo == philo->data->satisfied)
			break ;
	}
	//use fork
	pthread_mutex_unlock(&philo->data->all_forks[philo->fork_left]);
	pthread_mutex_unlock(&philo->data->all_forks[philo->fork_right]);
	return (NULL);
}
