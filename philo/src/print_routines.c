/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_routines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:28:48 by parnaldo          #+#    #+#             */
/*   Updated: 2023/01/16 15:37:32 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void print_routine(t_philo *phile, char *str)
{
    pthread_mutex_lock(philo->info->print);
    printf("Philosophers[%d] is %s\n", philo->id, str);
    pthread_mutex_unlock(philo->info->print);
}