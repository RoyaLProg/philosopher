/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 00:24:46 by ccambium          #+#    #+#             */
/*   Updated: 2022/08/01 22:15:34 by ccambium         ###   ########.fr       */
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
		usleep(x);
		die(philo, p);
	}
	usleep(philo->time_sleep);
	sleeping(p);
}

void	die(t_philosopher *philo, t_philo *p)
{
	t_philo	*tmp;

	death(p);
	tmp = philo->p_head;
	while (tmp != NULL)
	{
		if (tmp->n == p->n)
		{
			tmp = tmp->next;
			continue ;
		}
		pthread_detach(tmp->thread);
		pthread_mutex_destroy(&philo->forks[tmp->n - 1]);
		tmp = tmp->next;
	}
	pthread_mutex_destroy(&philo->forks[p->n - 1]);
	pthread_mutex_destroy(&philo->fork_lock);
	pthread_detach(p->thread);
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
	eating(p);
	usleep(philo->time_eat);
	p->lasteat = get_time();
	if (finish(philo))
		end(philo);
	return (0);
}
