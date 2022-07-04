/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   will_die.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 01:25:59 by ccambium          #+#    #+#             */
/*   Updated: 2022/07/04 01:32:18 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

long long int	will_die(t_philosopher *philo, t_philo *p, long long int t)
{
	if (gettimeofday() - p->lasteat + t > philo->params[1])
		return ((gettimeofday() - p->lasteat + t) - philo->params[1]);
	else
		return (0);
}
