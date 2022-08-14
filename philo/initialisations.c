/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:03:21 by ccambium          #+#    #+#             */
/*   Updated: 2022/08/14 18:17:33 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static char	init_mutex2(t_philosopher *philo)
{
	philo->end_mutex = (pthread_mutex_t *)
		ft_malloc(sizeof(pthread_mutex_t), philo);
	if (!philo->end_mutex || pthread_mutex_init(philo->end_mutex, NULL))
	{
		ft_error("Could not create end_mutex");
		abort_philo(philo, 0);
		return (0);
	}
	return (1);
}

static char	init_mutex(t_philosopher *philo)
{
	size_t	i;

	philo->forks = (pthread_mutex_t *)
		ft_malloc(sizeof(pthread_mutex_t) * philo->nb_philo + 1, philo);
	philo->b_fork = (char *)
		ft_malloc(sizeof(char) * philo->nb_philo + 1, philo);
	if (!philo->forks || !philo->b_fork)
	{
		ft_error("Could not allocate memory for forks");
		abort_philo(philo, 0);
		return (0);
	}
	i = -1;
	while (++i < philo->nb_philo)
	{
		if (pthread_mutex_init(&philo->forks[i], NULL) != 0)
		{
			abort_philo(philo, 0);
			return (0);
		}
		philo->b_fork[i] = 0;
	}
	return (init_mutex2(philo));
}

static char	init_thread(t_philo *p, t_philosopher *philo)
{
	t_package	*x;

	x = ft_malloc(sizeof(t_package), philo);
	x->philo = p;
	x->philosopher = philo;
	if (pthread_create(&p->thread, NULL, routine, x) != 0)
	{
		ft_error("Could not create thread !");
		return (0);
	}
	return (1);
}

static char	init_philo2(t_philosopher *philo, t_philo *p, size_t i)
{
	static t_philo	*last = NULL;

	p->last = last;
	if (i == 0)
		philo->p_head = p;
	p->n = i + 1;
	p->times_eat = 0;
	p->lasteat = 0;
	if (pthread_mutex_init(&p->m, NULL) != 0)
	{
		abort_philo(philo, 0);
		return (0);
	}
	if (!init_thread(p, philo))
	{
		abort_philo(philo, i);
		return (0);
	}
	pthread_mutex_lock(&p->m);
	if (last != NULL)
		last->next = p;
	last = p;
	pthread_mutex_unlock(&p->m);
	return (1);
}

char	init_philos(t_philosopher *philo)
{
	size_t			i;
	t_philo			*p;

	if (!init_mutex(philo))
	{
		ft_error("Could not initialize mutexes !");
		return (0);
	}
	i = -1;
	while (++i < philo->nb_philo)
	{
		p = (t_philo *)ft_malloc(sizeof(t_philo), philo);
		if (p == NULL)
		{
			ft_error("Could not allocate memory !");
			abort_philo(philo, i);
			return (0);
		}
		if (!init_philo2(philo, p, i))
			return (0);
	}
	pthread_mutex_lock(&p->m);
	p->next = NULL;
	pthread_mutex_unlock(&p->m);
	return (1);
}
