/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 20:42:35 by ccambium          #+#    #+#             */
/*   Updated: 2022/08/13 05:27:26 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	end(t_philosopher *philo)
{
	pthread_mutex_lock(philo->end_mutex);
	philo->end = 1;
	pthread_mutex_unlock(philo->end_mutex);
}
