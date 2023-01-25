/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:26:55 by parnaldo          #+#    #+#             */
/*   Updated: 2023/01/20 20:31:34 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	check_has_number(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_zero(char **argv, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	check_args(int ac, char **av)
{	
	if (ac >= 5 && ac <= 6)
	{
		if (check_has_number(ac, av) == 0)
			return (0);
	}
	else
		return (0);
	return (1);
}

int	waiting_to_die(t_philo *philo)
{
	if (philo->fork_right != philo->fork_left)
		return (0);
	while (42)
	{
		if (is_dead(philo))
			return (1);
	}
	return (0);
}
