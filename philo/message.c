/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 01:56:25 by ccambium          #+#    #+#             */
/*   Updated: 2022/07/15 23:56:42 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include <stdio.h>
#include <time.h>

void	death(t_philo	*p)
{
	printf("%lu philo %ld died\n", get_time() - p->start_time, p->n);
}

void	eating(t_philo *p)
{
	printf("%lu philo %ld is eating\n", get_time() - p->start_time, p->n);
}

void	thinking(t_philo *p)
{
	printf("%lu philo %ld is thinking\n", get_time() - p->start_time, p->n);
}

void	taking_fork(t_philo *p)
{
	printf("%lu philo %ld has taken a fork\n", get_time() - p->start_time,
		p->n);
}

void	sleeping(t_philo *p)
{
	printf("%lu philo %ld is sleeping\n", get_time() - p->start_time, p->n);
}
