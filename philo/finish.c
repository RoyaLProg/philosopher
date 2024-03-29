/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 20:38:21 by ccambium          #+#    #+#             */
/*   Updated: 2022/08/14 18:13:23 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

char	finish(t_philosopher *philo)
{
	t_philo	*p;
	size_t	i;

	if (philo->times_to_eat == -1)
		return (0);
	p = philo->p_head;
	i = -1;
	while (++i < philo->nb_philo)
	{
		pthread_mutex_lock(&p->m);
		if (p->times_eat < philo->times_to_eat)
		{
			pthread_mutex_unlock(&p->m);
			return (0);
		}
		pthread_mutex_unlock(&p->m);
		p = p->next;
	}
	return (1);
}
