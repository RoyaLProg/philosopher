/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:03:21 by ccambium          #+#    #+#             */
/*   Updated: 2022/07/07 23:45:29 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void	init_mutex(t_philo *p, t_philosopher *philo)
{
	pthread_mutex_t	*mutex;

	p->fork = (pthread_mutex_t *)ft_malloc(sizeof(pthread_mutex_t), philo);
	if (p->fork == NULL)
		return ;
	pthread_mutex_init(p->fork, NULL);
}

static void	init_thread(t_philo *p, t_philosopher *philo)
{
	p->thread = (pthread_t *)ft_malloc(sizeof(pthread_t), philo);
	if (p->thread == NULL)
		return ;
	pthread_create(p->thread, NULL, routine, p);
	pthread_join(p->thread, NULL);
}

static void	init_philo2(t_philosopher *philo, t_philo *p)
{
	p->lasteat = 0;
	p->forks[0] = 0;
	p->forks[1] = 0;
	init_thread(p, philo);
	init_mutex(p, philo);
}

void	init_philos(t_philosopher *philo)
{
	long long int	i;
	t_philo			*last;
	t_philo			*p;

	i = -1;
	last = NULL;
	while (++i < philo->params[0])
	{
		p = (t_philo *)ft_malloc(sizeof(t_philo), philo);
		if (p == NULL)
			return ;
		p->n = i + 1;
		p->times_eat = 0;
		p->last = last;
		if (last != NULL)
			last->next = p;
		if (i == 0)
			philo->p_head = p;
		last = p;
		init_philo2(philo, p);
	}
	p->next = NULL;
	philo->p_head->last = p;
}
