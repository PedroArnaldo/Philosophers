/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:26:30 by parnaldo          #+#    #+#             */
/*   Updated: 2023/01/25 12:11:49 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	join_and_free(t_info *data)
{
	int	i;

	i = -1;
	while (++i < data->num_of_philo)
	{
		pthread_join(data->philo[i].thread, NULL);
		pthread_mutex_destroy(&data->all_forks[i]);
	}
	free(data->all_forks);
	free(data->philo);
}

void	check_philo(t_philo *philo, t_info *data)
{
	int	i;

	while (42)
	{
		i = -1;
		if (data->someone_dead > 0 || data->satisfied == data->num_of_philo)
			break ;
		while (++i < data->num_of_philo)
			is_dead(&philo[i]);
		if (data->someone_dead > 0 || data->satisfied == data->num_of_philo)
			break ;
	}
}

int	main(int ac, char **av)
{
	t_info	data;
	t_philo	*philo;
	int		i;

	i = -1;
	memset(&data, 0, sizeof(data));
	memset(&philo, 0, sizeof(philo));
	if (!check_args(ac, av))
	{
		print_error();
		return (0);
	}
	data.time_start = get_time();
	philo = init_info(&data, philo, ac, av);
	if (philo)
		while (++i < data.num_of_philo)
			pthread_create(&philo[i].thread, NULL, &routines, &philo[i]);
	else
	{
		print_error();
		return (0);
	}
	check_philo(philo, &data);
	join_and_free(&data);
	return (0);
}
