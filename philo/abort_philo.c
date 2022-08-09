/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abort_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 20:10:46 by ccambium          #+#    #+#             */
/*   Updated: 2022/08/09 08:34:31 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	abort_philo(t_philosopher *philo, size_t n)
{
	size_t	i;
	t_philo	*p;

	ft_info("Aborting philosopher...");
	i = -1;
	p = philo->p_head;
	while (++i < n)
	{
		pthread_detach(p->thread);
		p = p->next;
	}
	if (philo->forks != NULL)
	{
		i = -1;
		while (++i < n)
			pthread_mutex_destroy(&philo->forks[i]);
	}
}
