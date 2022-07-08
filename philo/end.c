/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 20:42:35 by ccambium          #+#    #+#             */
/*   Updated: 2022/07/08 21:02:00 by ccambium         ###   ########.fr       */
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
		if (p->fork != NULL)
			pthread_mutex_destroy(p->fork);
		p = p->next;
	}
}
