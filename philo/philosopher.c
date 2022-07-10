/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:56:57 by ccambium          #+#    #+#             */
/*   Updated: 2022/07/09 20:18:41 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(void)
{
	t_philosopher	philo;

	philo.o_head = NULL;
	philo.p_head = NULL;
	philo.params[0] = 5;
	philo.params[1] = 2000;
	philo.params[2] = 350;
	philo.params[3] = 100;
	philo.times_to_eat = -1;
	// if (!verification(&philo))
	// 	return (EXIT_FAILURE);
	philo.start_time = get_time();
	if (!init_philos(&philo))
	{
		ft_info("Philosopher has been aborted");
		return (EXIT_FAILURE);
	}
	free_all(&philo);
	return (EXIT_SUCCESS);
}
