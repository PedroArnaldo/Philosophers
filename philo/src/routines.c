/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:07:24 by parnaldo          #+#    #+#             */
/*   Updated: 2023/01/20 09:04:26 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	take_fork(t_philo *philo)
{
	unsigned long ms_l;
	unsigned long ms_r;
	
	ms_l = time_now() - philo->data->time_start;
	pthread_mutex_lock(&philo->data->all_forks[philo->fork_right]);
	print_routinet(ms_l, philo, "has taken a fork.");
	ms_r = time_now() - philo->data->time_start;
	pthread_mutex_lock(&philo->data->all_forks[philo->fork_left]);
	print_routinet(ms_r, philo, "has taken a fork.");
}

void eat(t_philo *philo)
{
	long ms;

	pthread_mutex_lock(&philo->check);
	ms = time_now() - philo->data->time_start;
	philo->last_meals = time_now();
	print_routinet(ms, philo, "is eating	");
	if(philo->ate_times == philo->data->num_times_must_eat)
		philo->data->satisfied++;
	philo->ate_times++;
	usleep(philo->data->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->data->all_forks[philo->fork_left]);
	pthread_mutex_unlock(&philo->data->all_forks[philo->fork_right]);
	pthread_mutex_unlock(&philo->check);
}

void sleeping(t_philo *philo)
{
	long ms;

	ms = time_now() - philo->data->time_start;
	print_routinet(ms, philo, "is sleeping");
	usleep(philo->data->time_to_sleep * 1000);
}

void    think(t_philo *philo)
{
	long ms;

	ms = time_now() - philo->data->time_start;
    print_routinet(ms, philo, "is thinking");
}

void    *routines(void *arg)
{
    t_philo *philo;
    philo = (t_philo *) arg;
	if (philo->id % 2 == 0)
		usleep(philo->data->time_to_eat * 1000);
    while(42)
    {
		take_fork(philo);
		eat(philo);
        sleeping(philo);
        think(philo);
    }
    return (NULL);
}
