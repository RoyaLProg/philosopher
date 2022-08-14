/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_forks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 09:11:21 by ccambium          #+#    #+#             */
/*   Updated: 2022/08/14 19:40:14 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void	take_fork(t_philosopher *philo, t_philo *p)
{
	philo->b_fork[p->n - 1] = 1;
	if (p->n == philo->nb_philo)
		philo->b_fork[0] = 1;
	else
		philo->b_fork[p->n] = 1;
}

char	check_forks(t_philosopher *philo, t_philo *p)
{
	char	v;

	if (p->n == philo->nb_philo)
	{
		pthread_mutex_lock(&philo->forks[0]);
		pthread_mutex_lock(&philo->forks[p->n - 1]);
	}
	else
	{
		pthread_mutex_lock(&philo->forks[p->n - 1]);
		pthread_mutex_lock(&philo->forks[p->n]);
	}
	if (p->n == philo->nb_philo)
		v = philo->b_fork[p->n - 1] + philo->b_fork[0];
	else
		v = philo->b_fork[p->n - 1] + philo->b_fork[p->n];
	if (v == 0)
		take_fork(philo, p);
	pthread_mutex_unlock(&philo->forks[p->n - 1]);
	if (p->n == philo->nb_philo)
		pthread_mutex_unlock(&philo->forks[0]);
	else
		pthread_mutex_unlock(&philo->forks[p->n]);
	return (v);
}
