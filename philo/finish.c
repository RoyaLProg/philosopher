/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 20:38:21 by ccambium          #+#    #+#             */
/*   Updated: 2022/07/08 20:57:30 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

char	finish(t_philosopher *philo)
{
	t_philo	*p;

	if (philo->times_to_eat == -1)
		return (0);
	p = philo->p_head;
	while (p != NULL)
	{
		if (p->times_eat < philo->times_to_eat)
			return (0);
		p = p->next;
	}
	return (1);
}
