/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 01:56:25 by ccambium          #+#    #+#             */
/*   Updated: 2022/07/04 20:01:15 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include <stdio.h>
#include <time.h>

void	death(t_philosopher *philo, t_philo	*p)
{
	printf("%lu philo %d died ", timeoftheday() - philo->start_time, p->n);
}

void	eating(t_philosopher *philo, t_philo *p)
{
	printf("%lu philo %d is eating ", timeoftheday() - philo->start_time, p->n);
}

void	thinking(t_philosopher *philo, t_philo *p)
{
	printf("%lu philo %d is thinking ", timeoftheday() - philo->start_time,
		p->n);
}

void	taking_fork(t_philosopher *philo, t_philo *p)
{
	printf("%lu philo %d has taken forks ", timeoftheday() - philo->start_time,
		p->n);
}

void	sleeping(t_philosopher *philo, t_philo *p)
{
	printf("%lu philo %d is sleeping ", timeoftheday() - philo->start_time,
		p->n);
}
