/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 22:44:53 by ccambium          #+#    #+#             */
/*   Updated: 2022/07/04 01:06:55 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include <stdio.h>
#include <pthread.h>

void	*routine(void *arg)
{
	t_philo			*p;
	t_philosopher	*philo;
	t_package		*x;

	x = (t_package *)arg;
	p = x->philo;
	philo = x->philosopher;
	printf("je suis dans thread separer :D !\n");
	pthread_exit(NULL);
}
