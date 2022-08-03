/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 23:21:35 by ccambium          #+#    #+#             */
/*   Updated: 2022/07/31 23:02:25 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

char	start(t_philosopher *philo, t_philo *head)
{
	t_philo	*x;

	x = head;
	while (x != NULL)
	{
		if (pthread_join(x->thread, NULL) != 0)
		{
			ft_error("Could not join thread !");
			abort_philo(philo, philo->nb_philo);
			return (0);
		}
		x = x->next;
		usleep(800);
	}
	return (1);
}
