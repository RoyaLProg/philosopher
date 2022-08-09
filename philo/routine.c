/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 22:44:53 by ccambium          #+#    #+#             */
/*   Updated: 2022/08/01 22:58:58 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

#include <stdio.h>

// void	*routine(void *arg)
// {
// 	t_package	*x;

// 	usleep(50);
// 	x = (t_package *)arg;
// 	pthread_detach(x->philo->thread);
// 	printf("PHILO N : %lu | ENTRE DANS LA ROUTINE\n", x->philo->n);
// 	ft_free(x, x->philosopher);
// 	while (1)
// 		;
// 	printf("PHILO N : %lu | SORT DE LA ROUTINE\n", x->philo->n);
// 	return (NULL);
// }

void	*routine(void *arg)
{
	t_philo			*p;
	t_philosopher	*philo;
	t_package		*x;

	x = (t_package *)arg;
	p = x->philo;
	philo = x->philosopher;
	p->start_time = get_time();
	while (1)
	{
		if (p->n == philo->nb_philo)
		{
			pthread_mutex_lock(&philo->forks[0]);
			taking_fork(p);
			pthread_mutex_lock(&philo->forks[p->n - 1]);
			taking_fork(p);
		}
		else
		{
			pthread_mutex_lock(&philo->forks[p->n - 1]);
			taking_fork(p);
			pthread_mutex_lock(&philo->forks[p->n]);
			taking_fork(p);
		}
		eat(philo, p);
		if (p->n == philo->nb_philo)
		{
			pthread_mutex_unlock(&philo->forks[0]);
			pthread_mutex_unlock(&philo->forks[p->n - 1]);
		}
		else
		{
			pthread_mutex_unlock(&philo->forks[p->n - 1]);
			pthread_mutex_unlock(&philo->forks[p->n]);
		}
		p_sleep(philo, p);
		thinking(p);
	}
	return (NULL);
}
