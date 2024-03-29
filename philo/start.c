/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 23:21:35 by ccambium          #+#    #+#             */
/*   Updated: 2022/08/15 03:54:17 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

char	start(t_philosopher *philo, t_philo *head)
{
	t_philo	*x;

	x = head;
	philo->start_time = get_time();
	pthread_mutex_unlock(&philo->time);
	while (x->n != philo->nb_philo)
	{
		if (pthread_join(x->thread, NULL) != 0)
		{
			if (is_end(philo))
				continue ;
			ft_error("Could not join thread !");
			abort_philo(philo, philo->nb_philo);
			return (0);
		}
		x = x->next;
	}
	pthread_join(x->thread, NULL);
	return (1);
}
