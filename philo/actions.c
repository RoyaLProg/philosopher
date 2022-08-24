/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 00:24:46 by ccambium          #+#    #+#             */
/*   Updated: 2022/08/24 11:29:45 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

char	p_sleep(t_philosopher *philo, t_philo *p)
{
	suseconds_t	x;

	if (is_end(philo))
		return (1);
	sleeping(p, philo);
	x = will_die(philo, p, philo->time_sleep);
	if (x >= 0)
	{
		usleep(x * 1000);
		die(philo, p);
		release_forks(philo, p);
		return (1);
	}
	usleep(philo->time_sleep * 1000);
	return (0);
}

void	die(t_philosopher *philo, t_philo *p)
{
	pthread_mutex_lock(philo->end_mutex);
	if (philo->end)
	{
		pthread_mutex_unlock(philo->end_mutex);
		return ;
	}
	death(p, philo);
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
			return (1);
		}
		if (is_end(philo))
			return (1);
		usleep(500);
	}
	taking_fork(p, philo);
	taking_fork(p, philo);
	return (0);
}

char	eat2(t_philosopher *philo, t_philo *p)
{
	suseconds_t	x;

	x = will_die(philo, p, philo->time_eat);
	if (x >= 0)
	{
		usleep(x * 1000);
		die(philo, p);
		release_forks(philo, p);
		return (1);
	}
	usleep(philo->time_eat * 1000);
	release_forks(philo, p);
	return (0);
}

char	eat(t_philosopher *philo, t_philo *p)
{
	if (is_end(philo))
		return (1);
	if (check_death(philo, p))
	{
		die(philo, p);
		return (1);
	}
	eating(p, philo);
	pthread_mutex_lock(&p->m);
	p->times_eat++;
	pthread_mutex_unlock(&p->m);
	if (finish(philo))
	{
		end(philo);
		return (1);
	}
	p->lasteat = get_time();
	return (eat2(philo, p));
}
