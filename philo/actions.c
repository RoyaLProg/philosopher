/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 00:24:46 by ccambium          #+#    #+#             */
/*   Updated: 2022/08/14 18:30:24 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

char	p_sleep(t_philosopher *philo, t_philo *p)
{
	suseconds_t	x;

	if (is_end(philo))
		return (0);
	x = will_die(philo, p, philo->time_sleep);
	if (x >= 0)
	{
		if (is_end(philo))
			return (0);
		sleeping(p);
		usleep(x * 1000);
		die(philo, p);
		return (0);
	}
	if (is_end(philo))
		return (0);
	sleeping(p);
	usleep(philo->time_sleep * 1000);
	return (1);
}

void	die(t_philosopher *philo, t_philo *p)
{
	pthread_mutex_lock(philo->end_mutex);
	if (philo->end)
	{
		pthread_mutex_unlock(philo->end_mutex);
		return ;
	}
	death(p);
	philo->end = 1;
	pthread_mutex_unlock(philo->end_mutex);
}

char	take_forks(t_philosopher *philo, t_philo *p)
{
	while (check_forks(philo, p))
	{
		if (check_death(philo, p))
		{
			die(philo, p);
			return (0);
		}
		if (is_end(philo))
			return (0);
	}
	if (check_death(philo, p))
	{
		die(philo, p);
		return (0);
	}
	taking_fork(p);
	taking_fork(p);
	return (1);
}

char	eat(t_philosopher *philo, t_philo *p)
{
	if (check_death(philo, p))
	{
		die(philo, p);
		return (1);
	}
	if (is_end(philo))
		return (1);
	eating(p);
	usleep(philo->time_eat * 1000);
	p->lasteat = get_time();
	pthread_mutex_lock(&p->m);
	p->times_eat++;
	pthread_mutex_unlock(&p->m);
	release_forks(philo, p);
	if (finish(philo))
		end(philo);
	return (0);
}
