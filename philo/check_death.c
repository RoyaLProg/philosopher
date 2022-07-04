/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 22:32:43 by ccambium          #+#    #+#             */
/*   Updated: 2022/06/30 22:45:04 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	check_death(t_philo	*p, t_philosopher *philo)
{
	if (timeofday() - p->lasteat > philo->params[1])
		return (1);
	return (0);
}
