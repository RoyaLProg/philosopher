/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mysleep.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:21:24 by ccambium          #+#    #+#             */
/*   Updated: 2022/08/24 11:14:25 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

char	mysleep(suseconds_t t, t_philo *p, t_philosopher *philo)
{
	long	i;

	i = 0;
	while (!is_end(philo))
	{
		usleep(1000);
		i++;
		if (check_death(philo, p))
		{
			die(philo, p);
			return (1);
		}
		if (i == t)
			return (0);
	}
	return (1);
}
