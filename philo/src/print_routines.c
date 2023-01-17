/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_routines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:28:48 by parnaldo          #+#    #+#             */
/*   Updated: 2023/01/17 13:19:30 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void print_routine(t_philo *philo, char *str)
{
   // pthread_mutex_lock(&philo->data->print);
    printf("Philosophers[%d] is %s\n", philo->id, str);
    //pthread_mutex_unlock(&philo->data->print);
}
