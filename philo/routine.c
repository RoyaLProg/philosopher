/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 22:44:53 by ccambium          #+#    #+#             */
/*   Updated: 2022/07/08 21:05:51 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*routine(void *arg)
{
	t_philo			*p;
	t_philosopher	*philo;
	t_package		*x;

	x = (t_package *)arg;
	p = x->philo;
	philo = x->philosopher;
	ft_free(x, philo);
	while (1)
	{
		ft_free(philo->o_head, x);
		while (!eat(philo, p))
			if (check_death(philo, p))
				die(philo, p);
		p_sleep(philo, p);
		think(philo, p);
	}
	return (NULL);
}
