/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:26:38 by parnaldo          #+#    #+#             */
/*   Updated: 2023/01/12 17:38:28 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_info
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_times_must_eat;
	pthread_mutex_t print;
	pthread_mutex_t *all_forks;
} t_info;

typedef struct s_phile
{
	int				id;
	pthread_t		thread;
	struct s_info   *data;
	pthread_mutex_t  stop;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
} t_philo;


t_philo	*init_info(t_info *data, t_philo *philo, int argc, char **argv);

void   *routines(void *arg);

void	print_routine(t_philo *philo, char *str);

long	ft_atoi(const char *str);
int		ft_isdigit(int c);
int		check_has_number(int ac, char **av);

#endif
