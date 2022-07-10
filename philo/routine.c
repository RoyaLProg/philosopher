/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 22:44:53 by ccambium          #+#    #+#             */
/*   Updated: 2022/07/10 23:07:32 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

#include <stdio.h>

void	*routine(void *arg)
{
	t_package	*x;

	usleep(50);
	x = (t_package *)arg;
	printf("PHILO N : %lu | ENTRE DANS LA ROUTINE\n", x->philo->n);
	ft_free(x, x->philosopher);
	while (1)
		;
	return (NULL);
}

// void	*routine(void *arg)
// {
// 	t_philo			*p;
// 	t_philosopher	*philo;
// 	t_package		*x;

// 	x = (t_package *)arg;
// 	p = x->philo;
// 	philo = x->philosopher;
// 	ft_free(x, philo);
// 	while (1)
// 	{
// 		while (!eat(philo, p))
// 			if (check_death(philo, p))
// 				die(philo, p);
// 		p_sleep(philo, p);
// 		thinking(philo, p);
// 	}
// 	return (NULL);
// }
