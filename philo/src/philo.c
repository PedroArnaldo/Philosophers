/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:26:30 by parnaldo          #+#    #+#             */
/*   Updated: 2023/01/11 15:36:58 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int check_args(int ac, char **av)
{	
	if(ac >= 5 && ac <= 6)
	{
		if(check_has_number(ac, av) == 0)
			return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	printf("%d\n", check_args(ac, av));
    return (0);
}
