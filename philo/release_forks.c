/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_forks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 08:56:35 by ccambium          #+#    #+#             */
/*   Updated: 2022/08/14 09:22:44 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	release_forks(t_philosopher *philo, t_philo *p)
{
	if (p->forks[0])
	{
		pthread_mutex_unlock(&philo->forks[p->n - 1]);
		pthread_mutex_lock(philo->fork_mutex);
		philo->b_fork[p->n - 1] = 0;
		pthread_mutex_unlock(philo->fork_mutex);
	}
	if (p->n == philo->nb_philo && p->forks[1])
	{
		pthread_mutex_unlock(&philo->forks[0]);
		pthread_mutex_lock(philo->fork_mutex);
		philo->b_fork[0] = 0;
		pthread_mutex_unlock(philo->fork_mutex);
	}
	else if (p->forks[1])
	{
		pthread_mutex_unlock(&philo->forks[p->n]);
		pthread_mutex_lock(philo->fork_mutex);
		philo->b_fork[p->n] = 0;
		pthread_mutex_unlock(philo->fork_mutex);
	}
	p->forks[0] = 0;
	p->forks[1] = 0;
}
