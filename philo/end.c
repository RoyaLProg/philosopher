/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 20:42:35 by ccambium          #+#    #+#             */
/*   Updated: 2022/08/01 21:24:14 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	end(t_philosopher *philo)
{
	t_philo	*p;

	p = philo->p_head;
	while (p != NULL)
	{
		pthread_detach(p->thread);
		pthread_mutex_destroy(&philo->forks[p->n - 1]);
		p = p->next;
	}
}
