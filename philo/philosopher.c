/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:56:57 by ccambium          #+#    #+#             */
/*   Updated: 2022/07/01 22:38:12 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include <pthread.h>
#include <stdio.h>

int	main(void)
{
	pthread_t	threadtest;

	if (pthread_create(&threadtest, NULL, routine, NULL))
	{
		printf("ERROR");
		return (EXIT_FAILURE);
	}
	if (pthread_join(threadtest, NULL))
	{
		printf("ERROR CANNOT JOIN");
		return (EXIT_FAILURE);
	}
	printf("all good i guess");
	return (EXIT_SUCCESS);
}
