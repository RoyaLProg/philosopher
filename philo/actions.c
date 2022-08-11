/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 00:24:46 by ccambium          #+#    #+#             */
/*   Updated: 2022/08/11 16:06:07 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	p_sleep(t_philosopher *philo, t_philo *p)
{
	suseconds_t	x;

	x = will_die(philo, p, philo->time_sleep);
	if (x >= 0)
	{
		sleeping(p);
		usleep(x * 1000);
		die(philo, p);
	}
	sleeping(p);
	usleep(philo->time_sleep * 1000);
}

void	die(t_philosopher *philo, t_philo *p)
{
	death(p);
	philo->end = 1;
}

char	take_fork( t_philo *p, pthread_mutex_t *fork)
{
	if (pthread_mutex_lock(fork) == 0)
	{
		taking_fork(p);
		return (1);
	}
	return (0);
}

char	eat(t_philosopher *philo, t_philo *p)
{
	if (check_death(philo, p))
		return (1);
	eating(p);
	usleep(philo->time_eat * 1000);
	p->lasteat = get_time();
	if (finish(philo))
		end(philo);
	return (0);
}
