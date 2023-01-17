/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:07:24 by parnaldo          #+#    #+#             */
/*   Updated: 2023/01/17 16:39:38 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	take_fork(t_philo *philo)
{
	// pthread_mutex_lock(&philo->data->all_forks[philo->fork_left]);
	// pthread_mutex_lock(&philo->data->all_forks[philo->fork_right]);
	 print_routine(philo, "taking fork.");
	// pthread_mutex_unlock(&philo->data->all_forks[philo->fork_left]);
	// pthread_mutex_unlock(&philo->data->all_forks[philo->fork_right]);

}


void eat(t_philo *philo)
{
    //tenho que pegar o garfo direito e esquerdo
	//if(philo->use_fork)
	//{
		print_routine(philo, "is eating.");
		usleep(philo->data->time_to_eat * 1000);
	//	philo->use_fork = 0;
	//}
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
    while(42)
    {
		pthread_mutex_lock(&philo->stop);
	//	take_fork(philo);
		eat(philo);
        sleeping(philo);
        think(philo);
		sleep(1);
		pthread_mutex_unlock(&philo->stop);
    }
    return (NULL);
}
