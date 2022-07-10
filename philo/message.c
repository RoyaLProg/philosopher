/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 01:56:25 by ccambium          #+#    #+#             */
/*   Updated: 2022/07/09 20:29:18 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include <stdio.h>
#include <time.h>

void	death(t_philosopher *philo, t_philo	*p)
{
	printf("%lu philo %ld died ", get_time() - philo->start_time, p->n);
}

void	eating(t_philosopher *philo, t_philo *p)
{
	printf("%lu philo %ld is eating ", get_time() - philo->start_time, p->n);
}

void	thinking(t_philosopher *philo, t_philo *p)
{
	printf("%lu philo %ld is thinking ", get_time() - philo->start_time, p->n);
}

void	taking_fork(t_philosopher *philo, t_philo *p)
{
	printf("%lu philo %ld has taken forks ", get_time() - philo->start_time,
		p->n);
}

void	sleeping(t_philosopher *philo, t_philo *p)
{
	printf("%lu philo %ld is sleeping ", get_time() - philo->start_time, p->n);
}
