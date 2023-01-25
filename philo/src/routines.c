/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:07:24 by parnaldo          #+#    #+#             */
/*   Updated: 2023/01/25 13:23:43 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->all_forks[philo->fork_right]);
	print_routinet(philo, "has taken a fork");
	philo->use_fr = 1;
	if (waiting_to_die(philo))
		return ;
	pthread_mutex_lock(&philo->data->all_forks[philo->fork_left]);
	print_routinet(philo, "has taken a fork");
	philo->use_fl = 1;
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->check);
	philo->last_meals = time_now(philo);
	pthread_mutex_unlock(&philo->check);
	if (!is_dead(philo))
		print_routinet(philo, "is eating");
	philo->meals++;
	pthread_mutex_lock(&philo->check);
	if (philo->meals == philo->data->num_times_must_eat)
		philo->data->satisfied++;
	pthread_mutex_unlock(&philo->check);
	smart_sleep(philo->data->time_to_eat, philo);
	drop_fork(philo);
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
		if (is_dead(philo) || check_stop(philo))
			break ;
		take_fork(philo);
		if (is_dead(philo) || check_stop(philo))
			break ;
		eat(philo);
		if (is_dead(philo) || check_stop(philo))
			break ;
		sleeping(philo);
		if (is_dead(philo) || check_stop(philo))
			break ;
		think(philo);
	}
	drop_fork(philo);
	return (NULL);
}
