/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:26:38 by parnaldo          #+#    #+#             */
/*   Updated: 2023/01/23 15:11:57 by parnaldo         ###   ########.fr       */
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
	unsigned long	time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_times_must_eat;
	int				satisfied;
	int				someone_dead;
	pthread_mutex_t	print;
	pthread_mutex_t	*all_forks;
	struct s_philo	*philo;
	unsigned long	time_start;
}	t_info;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	struct s_info	*data;
	pthread_mutex_t	stop;
	pthread_mutex_t	check;
	int				fork_left;
	int				fork_right;
	unsigned long	last_meals;
	int				use_fl;
	int				use_fr;
	int				meals;
}	t_philo;

t_philo			*init_info(t_info *data, t_philo *philo, int argc, char **argv);
void			init_mutex(t_philo *philo);


void			print_error(void);
void			print_routinet(t_philo *philo, char *str);
void			*routines(void *arg);

unsigned long	time_now(t_philo *philo);
unsigned long	get_time(void);
void			smart_sleep(unsigned long time, t_philo *ph);

int				is_dead(t_philo *philo);
int				check_stop(t_philo *philo);
void			drop_fork(t_philo *philo);

long			ft_atoi(const char *str);
int				ft_isdigit(int c);

int				check_has_number(int ac, char **av);
int				check_args(int ac, char **av);
#endif
