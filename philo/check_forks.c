/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_forks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 09:11:21 by ccambium          #+#    #+#             */
/*   Updated: 2022/08/14 10:07:13 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

char	check_forks(t_philosopher *philo, t_philo *p)
{
	pthread_mutex_lock(philo->fork_mutex);
	if (p->n == philo->nb_philo)
	{
		if (philo->b_fork[0] == 0 && philo->b_fork[p->n - 1] == 0)
		{
			philo->b_fork[0] = 1;
			philo->b_fork[p->n - 1] = 1;
			pthread_mutex_unlock(philo->fork_mutex);
			return (0);
		}
	}
	else
	{
		if (philo->b_fork[p->n] == 0 && philo->b_fork[p->n - 1] == 0)
		{
			philo->b_fork[p->n] = 1;
			philo->b_fork[p->n - 1] = 1;
			pthread_mutex_unlock(philo->fork_mutex);
			return (0);
		}
	}
	pthread_mutex_unlock(philo->fork_mutex);
	return (1);
}
