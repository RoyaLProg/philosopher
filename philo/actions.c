/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 00:24:46 by ccambium          #+#    #+#             */
/*   Updated: 2022/07/10 21:28:11 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	p_sleep(t_philosopher *philo, t_philo *p)
{
	suseconds_t	x;

	x = will_die(philo, p, philo->params[3]);
	if (x >= 0)
	{
		usleep(x);
		die(philo, p);
	}
	usleep(philo->params[3]);
	sleeping(philo, p);
}

void	die(t_philosopher *philo, t_philo *p)
{
	t_philo	*tmp;

	death(philo, p);
	tmp = philo->p_head;
	while (tmp != NULL)
	{
		if (tmp->n == p->n)
		{
			tmp = tmp->next;
			continue ;
		}
		pthread_mutex_destroy(tmp->fork);
		pthread_detach(tmp->thread);
		tmp = tmp->next;
	}
	pthread_mutex_destroy(p->fork);
	pthread_detach(p->thread);
}

char	take_fork(t_philosopher *philo, t_philo *p, pthread_mutex_t *fork)
{
	if (pthread_mutex_lock(fork) == 0)
	{
		taking_fork(philo, p);
		return (1);
	}
	return (0);
}

char	eat(t_philosopher *philo, t_philo *p)
{
	if (take_fork(philo, p, p->fork))
	{
		if (take_fork(philo, p, p->last->fork))
		{
			p->lasteat = get_time();
			eating(philo, p);
			usleep(philo->params[2]);
			p->times_eat++;
			pthread_mutex_unlock(p->last->fork);
			pthread_mutex_unlock(p->fork);
			return (1);
		}
		else
		{
			pthread_mutex_unlock(p->fork);
			return (0);
		}
	}
	if (finish(philo))
		end(philo);
	return (0);
}
