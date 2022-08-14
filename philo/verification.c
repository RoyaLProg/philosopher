/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 04:42:01 by ccambium          #+#    #+#             */
/*   Updated: 2022/08/14 06:20:35 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static char	nb_philo(t_philosopher *philo, char *param)
{
	unsigned long long	v;
	size_t				x;

	if (param == NULL)
		return (0);
	if (param [0] == '-')
		return (0);
	if (!is_all_digit(param))
		return (0);
	x = ft_strlen(param);
	if (x > 10)
		return (0);
	if (x == 10 && param[0] >= '4' && param[1] > '2')
		return (0);
	v = ft_atollu(param);
	if (v > 4294967295)
		return (0);
	philo->nb_philo = v;
	return (1);
}

static char	suseconds(char *param, suseconds_t *buff)
{
	size_t	v;
	size_t	x;

	if (param == NULL)
		return (0);
	if (param [0] == '-')
		return (0);
	if (!is_all_digit(param))
		return (0);
	x = ft_strlen(param);
	if (x > 10)
		return (0);
	if (x == 10 && param[0] >= '2' && param[1] > '1')
		return (0);
	v = ft_atolu(param);
	if (v > 2147483647)
		return (0);
	*buff = v;
	return (1);
}

static char	times_to_eat(t_philosopher *philo, char *param)
{
	unsigned long long	v;
	size_t				x;

	if (param == NULL)
		return (0);
	if (param [0] == '-')
		return (0);
	if (!is_all_digit(param))
		return (0);
	x = ft_strlen(param);
	if (x > 19)
		return (0);
	if (x == 19 && param[1] > '2')
		return (0);
	v = ft_atollu(param);
	if (v > 9223372036854775807)
		return (0);
	philo->times_to_eat = v;
	return (1);
}

char	verification(t_philosopher *philo, char **av, int ac)
{
	if (ac <= 4 || ac > 6)
	{
		ft_info("Not enough or too much arguments");
		return (1);
	}
	if (!nb_philo(philo, av[1]))
		return (1);
	if (!suseconds(av[2], &philo->time_die))
		return (1);
	if (!suseconds(av[3], &philo->time_eat))
		return (1);
	if (!suseconds(av[4], &philo->time_sleep))
		return (1);
	if (av[5] != NULL)
	{
		if (!times_to_eat(philo, av[5]))
			return (1);
	}
	else
		philo->times_to_eat = -1;
	return (0);
}
