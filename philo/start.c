/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 23:21:35 by ccambium          #+#    #+#             */
/*   Updated: 2022/08/13 09:52:12 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

char	start(t_philosopher *philo, t_philo *head)
{
	t_philo	*x;

	x = head;
	while (x != NULL && !is_end(philo))
	{
		if (pthread_join(x->thread, NULL) != 0)
		{
			if (!is_end(philo))
				break ;
			ft_error("Could not join thread !");
			abort_philo(philo, philo->nb_philo);
			return (0);
		}
		x = x->next;
	}
	return (1);
}
