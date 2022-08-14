/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 22:44:53 by ccambium          #+#    #+#             */
/*   Updated: 2022/08/14 08:57:28 by ccambium         ###   ########.fr       */
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
		if (!take_forks(philo, p))
			return (NULL);
		if (eat(philo, p))
			return (NULL);
		release_forks(philo, p);
		if (!p_sleep(philo, p))
			return (NULL);
		if (is_end(philo))
			return (NULL);
		thinking(p);
	}
	return (EXIT_SUCCESS);
}
