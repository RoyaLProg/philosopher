/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:56:57 by ccambium          #+#    #+#             */
/*   Updated: 2022/08/14 06:22:53 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(int ac, char **av)
{
	t_philosopher	philo;

	philo.o_head = NULL;
	philo.p_head = NULL;
	philo.end = 0;
	if (verification(&philo, av, ac))
	{
		printf("verifications failed\n");
		return (EXIT_FAILURE);
	}
	if (!init_philos(&philo))
	{
		ft_info("Philosopher has been aborted\n");
		return (EXIT_FAILURE);
	}
	if (!start(&philo, philo.p_head))
	{
		ft_info("Philosopher has been aborted\n");
		return (EXIT_FAILURE);
	}
	free_all(&philo);
	return (EXIT_SUCCESS);
}
