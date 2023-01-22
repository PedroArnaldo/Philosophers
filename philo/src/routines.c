/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:07:24 by parnaldo          #+#    #+#             */
/*   Updated: 2023/01/22 20:29:16 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->all_forks[philo->fork_right]);
	print_routinet(philo, "has taken a fork");
	philo->use_fr = 1;
	if (philo->fork_right == philo->fork_left)
		smart_sleep(philo->data->time_to_die, philo);
	pthread_mutex_lock(&philo->data->all_forks[philo->fork_left]);
	print_routinet(philo, "has taken a fork");
	philo->use_fl = 1;
}

void	eat(t_philo *philo)
{
	philo->last_meals = time_now(philo);
	//printf("%lu \n", time_now(philo) - philo->last_meals);
	if(!is_dead(philo))
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
		if (is_dead(philo) || check_stop(philo))
			break ;
		if (philo->data->num_of_philo == philo->data->satisfied)
			break ;
	}
	if (philo->use_fl)
		pthread_mutex_unlock(&philo->data->all_forks[philo->fork_left]);
	if (philo->use_fr)
		pthread_mutex_unlock(&philo->data->all_forks[philo->fork_right]);
	return (NULL);
}
