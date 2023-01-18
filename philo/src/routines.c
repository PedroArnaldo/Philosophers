/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:07:24 by parnaldo          #+#    #+#             */
/*   Updated: 2023/01/18 16:31:28 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	take_fork(t_philo *philo)
{
	long ms_l;
	long ms_r;
	
	ms_l = time_now() - philo->data->time_start;
	pthread_mutex_lock(&philo->data->all_forks[philo->fork_left]);
	print_routinet(ms_l, philo, "has taken a fork.");
	ms_r = time_now() - philo->data->time_start;
	pthread_mutex_lock(&philo->data->all_forks[philo->fork_right]);
	print_routinet(ms_r, philo, "has taken a fork.");
	philo->use_fork = 1;

}

void eat(t_philo *philo)
{
	long ms;

	if(philo->use_fork)
	{
		ms = time_now() - philo->data->time_start;
		philo->last_meals = ms;
		print_routinet(ms, philo, "is eating.");
		usleep(philo->data->time_to_eat * 1000);
		philo->use_fork = 0;
		pthread_mutex_unlock(&philo->data->all_forks[philo->fork_left]);
		pthread_mutex_unlock(&philo->data->all_forks[philo->fork_right]);
	}
}

void sleeping(t_philo *philo)
{
	long ms;

	ms = time_now() - philo->data->time_start;
    print_routinet(ms, philo, "is spleeping.");
	usleep(philo->data->time_to_sleep * 1000);
}

void    think(t_philo *philo)
{
	long ms;

	ms = time_now() - philo->data->time_start;
    print_routinet(ms, philo, "is thinking.");
}

void    *routines(void *arg)
{
    t_philo *philo;
    philo = (t_philo *) arg;
	if (philo->id % 2 == 0)
		usleep(100 * 1000);
    while(42)
    {
		is_dead(philo);
		take_fork(philo);
		eat(philo);
        sleeping(philo);
        think(philo);
    }
    return (NULL);
}
