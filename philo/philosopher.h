/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 23:49:38 by ccambium          #+#    #+#             */
/*   Updated: 2022/07/08 00:25:08 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_philo
{
	pthread_t		thread;
	size_t			times_eat;
	size_t			n;
	pthread_mutex_t	*fork;
	char			forks[2];
	size_t			lasteat;
	struct s_philo	*last;
	struct s_philo	*next;
}	t_philo;

typedef struct s_obj
{
	void	*ptr;
	void	*next;
}	t_obj;

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

typedef struct s_package
{
	t_philo			*philo;
	t_philosopher	*philosopher;
}	t_package;

void			*routine(void *arg);
void			p_sleep(t_philosopher *philo, t_philo *p);
void			die(t_philosopher *philo, t_philo *p);
char			eat(t_philosopher *philo, t_philo *p);
void			think(t_philosopher *philo, t_philo *p);
void			*ft_malloc(size_t size, t_philosopher *philo);
void			ft_free(void *ptr, t_philosopher *philo);
void			free_all(t_philosopher *philo);
void			init_philos(t_philosopher *philo);
void			add_end_obj(t_obj *head, t_obj *obj);
int				check_death(t_philo	*p, t_philosopher *philo);
void			taking_fork(t_philosopher *philo, t_philo *p);
void			sleeping(t_philosopher *philo, t_philo *p);
void			thinking(t_philosopher *philo, t_philo *p);
void			eating(t_philosopher *philo, t_philo *p);
void			death(t_philosopher *philo, t_philo *p);
long long int	will_die(t_philosopher *philo, t_philo *p, long long int t);

#endif
