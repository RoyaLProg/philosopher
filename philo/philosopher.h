/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 23:49:38 by ccambium          #+#    #+#             */
/*   Updated: 2022/07/10 21:23:53 by ccambium         ###   ########.fr       */
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
	long long int	times_eat;
	size_t			n;
	pthread_mutex_t	*fork;
	suseconds_t		lasteat;
	struct s_philo	*last;
	struct s_philo	*next;
}	t_philo;

typedef struct s_obj
{
	void	*ptr;
	void	*next;
}	t_obj;

/*
 * param = [nb_philo, time_die, time_eat, time_sleep]
*/
typedef struct s_philosopher
{
	suseconds_t		params[3];
	long long int	times_to_eat;
	t_obj			*o_head;
	t_philo			*p_head;
	suseconds_t		start_time;
}	t_philosopher;

typedef struct s_package
{
	t_philo			*philo;
	t_philosopher	*philosopher;
}	t_package;

char			finish(t_philosopher *philo);
char			init_philos(t_philosopher *philo);
char			eat(t_philosopher *philo, t_philo *p);
char			check_death(t_philosopher *philo, t_philo *p);

void			*routine(void *arg);
void			ft_info(const char *s);
void			ft_error(const char *s);
void			end(t_philosopher *philo);
void			free_all(t_philosopher *philo);
void			add_end_obj(t_obj *head, t_obj *obj);
void			die(t_philosopher *philo, t_philo *p);
void			think(t_philosopher *philo, t_philo *p);
void			death(t_philosopher *philo, t_philo *p);
void			ft_free(void *ptr, t_philosopher *philo);
void			eating(t_philosopher *philo, t_philo *p);
void			p_sleep(t_philosopher *philo, t_philo *p);
void			sleeping(t_philosopher *philo, t_philo *p);
void			thinking(t_philosopher *philo, t_philo *p);
void			abort_philo(t_philosopher *philo, size_t n);
void			*ft_malloc(size_t size, t_philosopher *philo);
void			taking_fork(t_philosopher *philo, t_philo *p);

size_t			ft_strlen(const char *s);

suseconds_t		get_time(void);
suseconds_t		will_die(t_philosopher *philo, t_philo *p, long long int t);

#endif
