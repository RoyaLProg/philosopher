/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   will_die.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 01:25:59 by ccambium          #+#    #+#             */
/*   Updated: 2022/07/08 19:44:35 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

suseconds_t	will_die(t_philosopher *philo, t_philo *p, long long int t)
{
	if (p->lasteat == 0)
	{
		if (get_time() - philo->start_time + t > philo->params[1])
			return (get_time() - philo->start_time + t - philo->params[1]);
		else
			return (-1);
	}
	if (get_time() - p->lasteat + t > philo->params[1])
		return ((get_time() - p->lasteat + t) - philo->params[1]);
	else
		return (-1);
}
