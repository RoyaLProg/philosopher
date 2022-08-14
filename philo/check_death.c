/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 22:32:43 by ccambium          #+#    #+#             */
/*   Updated: 2022/08/14 06:14:56 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

char	check_death(t_philosopher *philo, t_philo *p)
{
	if (p->lasteat == 0)
	{
		if (get_time() - p->start_time > philo->time_die)
			return (1);
	}
	else if (get_time() - p->lasteat > philo->time_die)
		return (1);
	return (0);
}
