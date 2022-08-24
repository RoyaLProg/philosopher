/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 22:44:53 by ccambium          #+#    #+#             */
/*   Updated: 2022/08/24 10:37:07 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

#include <stdio.h>

static void	*alone_routine(t_philo *p, t_philosopher *philo)
{
	taking_fork(p, philo);
	usleep(philo->time_die * 1000);
	death(p, philo);
	return (NULL);
}

void	*routine(void *arg)
{
	t_philo			*p;
	t_philosopher	*philo;
	t_package		*x;

	x = (t_package *)arg;
	p = x->philo;
	philo = x->philosopher;
	if (philo->nb_philo == 1)
		return (alone_routine(p, philo));
	while (1)
	{
		if (take_forks(philo, p))
			return (NULL);
		if (eat(philo, p))
			return (NULL);
		if (p_sleep(philo, p))
			return (NULL);
		if (is_end(philo))
			return (NULL);
		thinking(p, philo);
	}
	return (EXIT_SUCCESS);
}
