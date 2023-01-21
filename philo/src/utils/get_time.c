/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:19:37 by parnaldo          #+#    #+#             */
/*   Updated: 2023/01/21 19:06:24 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

unsigned long	get_time(void)
{
	struct timeval	tv;
	unsigned long	mili;

	gettimeofday(&tv, NULL);
	mili = tv.tv_sec * 1000;
	mili += tv.tv_usec / 1000;
	return (mili);
}

unsigned long	time_now(t_philo *philo)
{
	return (get_time() - philo->data->time_start);
}
