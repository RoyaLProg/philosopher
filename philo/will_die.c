/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   will_die.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 01:25:59 by ccambium          #+#    #+#             */
/*   Updated: 2022/08/01 21:28:21 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

suseconds_t	will_die(t_philosopher *philo, t_philo *p, long long int t)
{
	if (p->lasteat == 0)
	{
		if (get_time() - p->start_time + t > philo->time_die)
			return (get_time() - p->start_time + t - philo->time_die);
		else
			return (-1);
	}
	if (get_time() - p->lasteat + t > philo->time_die)
		return ((get_time() - p->lasteat + t) - philo->time_die);
	else
		return (-1);
}
