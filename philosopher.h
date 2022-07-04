/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 23:49:38 by ccambium          #+#    #+#             */
/*   Updated: 2022/07/04 19:43:23 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H
# include <stdlib.h>
# include <pthread.h>

/*
 * param = [nb_philo, time_die, time_eat, time_sleep(, must_eat)]
*/
typedef struct s_philosopher
{
	long long int	params[4];
	t_obj			*o_head;
	t_philo			*p_head;
	size_t			start_time;
}	t_philosopher;

typedef struct s_philo
{
	pthread_t		thread;
	size_t			times_eat;
	size_t			n;
	pthread_mutex_t	fork;
	size_t			lasteat;
	t_philo			*last;
	t_philo			*next;
}	t_philo;

typedef struct s_obj
{
	void	*ptr;
	void	*next;
}	t_obj;

typedef struct s_package
{
	t_philo			*philo;
	t_philosopher	*philosopher;
}	t_package;


void	*routine(void *arg);
#endif
