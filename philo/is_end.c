/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 09:44:32 by ccambium          #+#    #+#             */
/*   Updated: 2022/08/13 09:45:29 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

char	is_end(t_philosopher *philo)
{
	pthread_mutex_lock(philo->end_mutex);
	if (philo->end)
	{
		pthread_mutex_unlock(philo->end_mutex);
		return (1);
	}
	pthread_mutex_unlock(philo->end_mutex);
	return (0);
}
