/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:16:05 by parnaldo          #+#    #+#             */
/*   Updated: 2023/01/18 16:41:50 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	is_dead(t_philo *philo)
{
	int ms;

	ms = time_now() - philo->data->time_start;
	if(philo->last_meals >= philo->data->time_to_die)
		printf("%d %d died\n", ms, philo->id);
}
