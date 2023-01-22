/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_routines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:28:48 by parnaldo          #+#    #+#             */
/*   Updated: 2023/01/22 17:48:15 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_routinet(t_philo *philo, char *str)
{
	if (check_stop(philo))
		return ;
	/* if (is_dead(philo))
	{
		printf("%ldms %d %s\n", time_now(philo), philo->id, "died");
		return ;
	} */
	pthread_mutex_lock(&philo->data->print);
	printf("%ldms %d %s\n", time_now(philo), philo->id, str);
	pthread_mutex_unlock(&philo->data->print);
}
