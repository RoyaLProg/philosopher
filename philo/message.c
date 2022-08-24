/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 01:56:25 by ccambium          #+#    #+#             */
/*   Updated: 2022/08/24 11:45:58 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include <stdio.h>
#include <time.h>

void	death(t_philo	*p, t_philosopher *philo)
{
	pthread_mutex_lock(&philo->time);
	printf("%lu philo %ld died\n", get_time() - philo->start_time, p->n);
	pthread_mutex_unlock(&philo->time);
}

void	eating(t_philo *p, t_philosopher *philo)
{
	pthread_mutex_lock(philo->end_mutex);
	pthread_mutex_lock(&philo->time);
	if (!philo->end)
		printf("%lu philo %ld is eating\n", get_time() - philo->start_time,
			p->n);
	pthread_mutex_unlock(&philo->time);
	pthread_mutex_unlock(philo->end_mutex);
}

void	thinking(t_philo *p, t_philosopher *philo)
{
	pthread_mutex_lock(philo->end_mutex);
	pthread_mutex_lock(&philo->time);
	if (!philo->end)
		printf("%lu philo %ld is thinking\n", get_time() - philo->start_time,
			p->n);
	pthread_mutex_unlock(&philo->time);
	pthread_mutex_unlock(philo->end_mutex);
}

void	taking_fork(t_philo *p, t_philosopher *philo)
{
	pthread_mutex_lock(philo->end_mutex);
	pthread_mutex_lock(&philo->time);
	if (!philo->end)
		printf("%lu philo %ld has taken a fork\n",
			get_time() - philo->start_time, p->n);
	pthread_mutex_unlock(&philo->time);
	pthread_mutex_unlock(philo->end_mutex);
}

void	sleeping(t_philo *p, t_philosopher *philo)
{
	pthread_mutex_lock(philo->end_mutex);
	pthread_mutex_lock(&philo->time);
	if (!philo->end)
		printf("%lu philo %ld is sleeping\n", get_time() - philo->start_time,
			p->n);
	pthread_mutex_unlock(&philo->time);
	pthread_mutex_unlock(philo->end_mutex);
}
