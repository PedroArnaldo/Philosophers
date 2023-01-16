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
	//struct s_philo	**philos;
} t_info;

typedef struct s_phile
{
	int				id;
	struct s_info	*info;
	//unsigned long	last_meal;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
	//unsigned long	time_start;
	//long long		last_meal;
	pthread_t		thread;
} t_philo;

long	ft_atoi(const char *str);
int		ft_isdigit(int c);
int		check_has_number(int ac, char **av);
int		init_info(t_info *info, int ac, char **av);
#endif
