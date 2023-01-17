/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:07:24 by parnaldo          #+#    #+#             */
/*   Updated: 2023/01/17 18:09:36 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->all_forks[philo->fork_left]);
	print_routine(philo, "taking fork.");
	pthread_mutex_lock(&philo->data->all_forks[philo->fork_right]);
	print_routine(philo, "taking fork.");
	philo->use_fork = 1;

}


void eat(t_philo *philo)
{
	if(philo->use_fork)
	{
		print_routine(philo, "is eating.");
		usleep(philo->data->time_to_eat * 1000);
		philo->use_fork = 0;
		pthread_mutex_unlock(&philo->data->all_forks[philo->fork_left]);
		pthread_mutex_unlock(&philo->data->all_forks[philo->fork_right]);
	}
}

void sleeping(t_philo *philo)
{
    print_routine(philo, "is spleeping.");
	usleep(philo->data->time_to_sleep * 1000);
}

void    think(t_philo *philo)
{
    print_routine(philo, "is thinking.");
}

void    *routines(void *arg)
{
    t_philo *philo;
    philo = (t_philo *) arg;
	if (philo->id % 2 == 0)
		usleep(100 * 1000);
    while(42)
    {
	//	pthread_mutex_lock(&philo->stop);
		take_fork(philo);
		eat(philo);
        sleeping(philo);
        think(philo);
	//	pthread_mutex_unlock(&philo->stop);
    }
    return (NULL);
}
