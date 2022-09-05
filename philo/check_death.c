/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 22:32:43 by ccambium          #+#    #+#             */
/*   Updated: 2022/08/24 12:05:17 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

char	check_death(t_philosopher *philo, t_philo *p)
{
	if (p->lasteat == 0)
	{
		pthread_mutex_lock(&philo->time);
		if (get_time() - philo->start_time > philo->time_die)
		{
			pthread_mutex_unlock(&philo->time);
			return (1);
		}
		pthread_mutex_unlock(&philo->time);
	}
	else if (get_time() - p->lasteat > philo->time_die)
		return (1);
	return (0);
}
