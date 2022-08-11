/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 00:24:46 by ccambium          #+#    #+#             */
/*   Updated: 2022/08/11 22:16:29 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

char	p_sleep(t_philosopher *philo, t_philo *p)
{
	suseconds_t	x;

	if (philo->end)
		return (0);
	x = will_die(philo, p, philo->time_sleep);
	if (x >= 0)
	{
		if (philo->end)
			return (0);
		sleeping(p);
		usleep(x * 1000);
		die(philo, p);
		return (0);
	}
	if (philo->end)
		return (0);
	sleeping(p);
	usleep(philo->time_sleep * 1000);
	return (1);
}

void	die(t_philosopher *philo, t_philo *p)
{
	size_t	i;

	i = 0;
	death(p);
	pthread_mutex_lock(philo->end_mutex);
	philo->end = 1;
	pthread_mutex_unlock(philo->end_mutex);
	leave(philo, p);
	while (i < philo->nb_philo)
	{
		pthread_mutex_destroy(&philo->forks[i]);
		i++;
	}
	pthread_mutex_destroy(philo->end_mutex);
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

void	leave(t_philosopher *philo, t_philo *p)
{
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
}
