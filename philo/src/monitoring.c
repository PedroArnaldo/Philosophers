/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:16:05 by parnaldo          #+#    #+#             */
/*   Updated: 2023/01/19 22:27:27 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	is_dead(t_philo *philo)
{
	unsigned long ms;
	
	ms = time_now() - philo->data->time_start;
	if(philo->last_meals > (unsigned long) philo->data->time_to_die)
		print_routinet(ms, philo, "did");
}
