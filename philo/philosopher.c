/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:56:57 by ccambium          #+#    #+#             */
/*   Updated: 2022/08/01 21:27:30 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(void)
{
	t_philosopher	philo;

	philo.o_head = NULL;
	philo.p_head = NULL;
	philo.nb_philo = 5;
	philo.time_die = 50500;
	philo.time_eat = 10250;
	philo.time_sleep = 5000;
	philo.times_to_eat = -1;
	if (!init_philos(&philo))
	{
		ft_info("Philosopher has been aborted");
		return (EXIT_FAILURE);
	}
	if (!start(&philo, philo.p_head))
	{
		ft_info("Philosopher has been aborted");
		return (EXIT_FAILURE);
	}
	free_all(&philo);
	return (EXIT_SUCCESS);
}
