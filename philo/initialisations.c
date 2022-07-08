/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:03:21 by ccambium          #+#    #+#             */
/*   Updated: 2022/07/08 20:10:13 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static char	init_mutex(t_philo *p, t_philosopher *philo)
{
	pthread_mutex_t	*mutex;

	p->fork = (pthread_mutex_t *)ft_malloc(sizeof(pthread_mutex_t), philo);
	if (p->fork == NULL)
		return ;
	if (pthread_mutex_init(p->fork, NULL) != 0)
	{
		ft_error("Could not initialize mutex !");
		return (0);
	}
	return (1);
}

static char	init_thread(t_philo *p, t_philosopher *philo)
{
	p->thread = (pthread_t *)ft_malloc(sizeof(pthread_t), philo);
	if (p->thread == NULL)
		return ;
	if (pthread_create(p->thread, NULL, routine, p) != 0)
	{
		ft_error("Could not create thread !");
		return (0);
	}
	if (pthread_join(p->thread, NULL) != 0)
	{
		ft_error("Could not join thread !");
		return (0);
	}
	return (1);
}

static char	init_philo2(t_philosopher *philo, t_philo *p, size_t i,
						t_philo *last)
{
	p->last = last;
	if (i == 0)
		philo->p_head = p;
	p->n = i + 1;
	p->times_eat = 0;
	p->lasteat = 0;
	if (!init_thread(p, philo))
		return (0);
	if (!init_mutex(p, philo))
		return (0);
	if (last != NULL)
		last->next = p;

	return (1);
}

void	init_philos(t_philosopher *philo)
{
	size_t			i;
	t_philo			*last;
	t_philo			*p;

	i = -1;
	last = NULL;
	while (++i < philo->params[0])
	{
		p = (t_philo *)ft_malloc(sizeof(t_philo), philo);
		if (p == NULL)
		{
			ft_error("Could not allocate memory !");
			abort_philo(philo, p, i);
			return (0);
		}
		last = p;
		if (!init_philo2(philo, p, i, last))
		{
			abort_philo(philo, p, i);
			return (0);
		}
	}
	p->next = NULL;
	philo->p_head->last = p;
	return (1);
}
