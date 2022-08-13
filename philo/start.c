/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 23:21:35 by ccambium          #+#    #+#             */
/*   Updated: 2022/08/13 05:20:15 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

char	start(t_philosopher *philo, t_philo *head)
{
	t_philo	*x;

	x = head;
	while (x != NULL && philo->end == 0)
	{
		if (pthread_join(x->thread, NULL) != 0)
		{
			if (philo->end == 0)
				break ;
			ft_error("Could not join thread !");
			abort_philo(philo, philo->nb_philo);
			return (0);
		}
		x = x->next;
	}
	return (1);
}
