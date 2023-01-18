/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:19:37 by parnaldo          #+#    #+#             */
/*   Updated: 2023/01/18 06:16:37 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

long    time_now(void)
{

    struct timeval tv;
    long    mili;
    
    gettimeofday(&tv, NULL);
    mili = tv.tv_sec * 1000;
    mili = tv.tv_usec / 1000;
    return (mili);
}