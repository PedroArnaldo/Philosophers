/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_routines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:28:48 by parnaldo          #+#    #+#             */
/*   Updated: 2023/01/20 20:27:13 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_routinet(long ms, t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->data->print);
	printf("%ldms %d %s\n", ms, philo->id, str);
	pthread_mutex_unlock(&philo->data->print);
}
