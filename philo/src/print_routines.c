/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_routines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:28:48 by parnaldo          #+#    #+#             */
/*   Updated: 2023/01/23 13:21:52 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_routinet(t_philo *philo, char *str)
{
	if (check_stop(philo) || is_dead(philo))
		return ;
	pthread_mutex_lock(&philo->data->print);
	printf("%ldms\t%d\t %s\n", time_now(philo), philo->id, str);
	pthread_mutex_unlock(&philo->data->print);
}

void	print_error(void)
{
	printf("\033[0;31m");
	printf("Error\n");
	printf("\033[0m");
}
