/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:07:24 by parnaldo          #+#    #+#             */
/*   Updated: 2023/01/16 15:28:14 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int eat(t_philo philo)
{
    //tem que retonar se ele conseguir pegar o garfo
}

void sleeping(t_philo philo)
{
    
}

void    think(t_philo philo)
{

}

void    *routines(t_philo philo)
{
    while(1)
    {
        eat(philo);
        sleeping(philo);
        think(philo);
    }
}