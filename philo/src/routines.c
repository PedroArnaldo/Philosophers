/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:07:24 by parnaldo          #+#    #+#             */
/*   Updated: 2023/01/17 10:27:31 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void eat(t_philo *philo)
{
    //tenho que pegar o garfo direito e esquerdo
    //print_routine(philo, "is eating.");
    printf("Philosophers[%d] is %s\n", philo->id, "is eating.");
}

void sleeping(t_philo *philo)
{
    //print_routine(philo, "is spleeping.");
    printf("Philosophers[%d] is %s\n", philo->id, "is spleeping.");
}

void    think(t_philo *philo)
{
    //print_routine(philo, "is thinking.");
    printf("Philosophers[%d] is %s\n", philo->id, "is thinking.");
}

void    *routines(void *arg)
{
    t_philo *philo;

    philo = (t_philo *) arg;
    while(42)
    {
        //printf("number of philo: %d \n", philo->data->num_of_philo);
        pthread_mutex_lock(&philo->stop);
        eat(philo);
        sleeping(philo);
        think(philo);
        sleep(1);
        pthread_mutex_unlock(&philo->stop);
    }
    return (NULL);
}