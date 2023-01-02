/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:26:30 by parnaldo          #+#    #+#             */
/*   Updated: 2023/01/01 00:26:44 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void *test_thread(void *arg)
{
	int *n = (int *)arg;
	printf("Estou na thread %d\n", *n);
	printf("Estou saindo da thread %d\n", *n);
	usleep(2);
	return (NULL);
}

int	main(int ac, char **av)
{
	t_info info;
	pthread_t *thread;
	int i;

	if(!av[1])
		return (0);
	i = 0;
	(void) ac;
	info.num_of_philo = ft_atoi(av[1]);
	thread = malloc(sizeof(thread) * info.num_of_philo);
	while (i < info.num_of_philo)
	{
		pthread_create(&(thread[i]), NULL, &test_thread, &i);
		pthread_join(thread[i], NULL);
		i++;
	}
	printf("Number philo: %d", info.num_of_philo);
	return (0);
}
