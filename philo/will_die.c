/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   will_die.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 01:25:59 by ccambium          #+#    #+#             */
/*   Updated: 2022/08/15 04:16:03 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

suseconds_t	will_die(t_philosopher *philo, t_philo *p, long long int t)
{
	if (p->lasteat == 0)
	{
		pthread_mutex_lock(&philo->time);
		if (get_time() - philo->start_time + t >= philo->time_die)
		{
			pthread_mutex_unlock(&philo->time);
			return (get_time() - philo->start_time + t - philo->time_die);
		}
		else
		{
			pthread_mutex_unlock(&philo->time);
			return (-1);
		}
	}
	if (get_time() - p->lasteat + t >= philo->time_die)
		return ((get_time() - p->lasteat + t) - philo->time_die);
	else
		return (-1);
}
