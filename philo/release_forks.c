/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_forks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 08:56:35 by ccambium          #+#    #+#             */
/*   Updated: 2022/08/14 16:49:53 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	release_forks(t_philosopher *philo, t_philo *p)
{
	pthread_mutex_lock(&philo->forks[p->n - 1]);
	philo->b_fork[p->n - 1] = 0;
	pthread_mutex_unlock(&philo->forks[p->n - 1]);
	if (p->n == philo->nb_philo)
	{
		pthread_mutex_lock(&philo->forks[0]);
		philo->b_fork[0] = 0;
		pthread_mutex_unlock(&philo->forks[0]);
	}
	else
	{
		pthread_mutex_lock(&philo->forks[p->n]);
		philo->b_fork[p->n] = 0;
		pthread_mutex_unlock(&philo->forks[p->n]);
	}
}
