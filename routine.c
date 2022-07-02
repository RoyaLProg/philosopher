/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 22:44:53 by ccambium          #+#    #+#             */
/*   Updated: 2022/06/28 02:53:31 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include <stdio.h>
#include <pthread.h>

void	*routine(void *arg)
{
	(void)arg;
	printf("je suis dans thread separer :D !\n");
	pthread_exit(NULL);
}
