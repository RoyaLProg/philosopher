/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 00:24:46 by ccambium          #+#    #+#             */
/*   Updated: 2022/07/04 20:01:07 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

// void	eat(t_philosopher *philo, t_philo *p)
// {
// }

void	sleep(t_philosopher *philo, t_philo *p)
{
	long long int	x;

	x = will_die();
	if (x > 0)
	{
		p->lasteat = gettimeofday();
		usleep(x);
	}
	sleeping(philo, p);
	usleep(philo->params[2]);
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
		pthread_mutex_destroy(&tmp->fork);
		pthread_detach(tmp->thread);
		tmp = tmp->next;
	}
	pthread_mutex_destroy(&p->fork);
	pthread_detach(p->thread);
}

char	take_fork(t_philosopher *philo, t_philo *p)
{
	if (pthread_mutex_lock(&p->fork) == 0)
	{
		taking_fork(philo, p);
		return (1);
	}
	return (0);
}
