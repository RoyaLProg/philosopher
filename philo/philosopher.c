/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:56:57 by ccambium          #+#    #+#             */
/*   Updated: 2022/07/08 23:03:26 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(void)
{
	t_philosopher	philo;

	philo.o_head = NULL;
	philo.p_head = NULL;
	if (!verification(&philo))
		return (0);
	init_philos(&philo);
	free_all(&philo);
}
