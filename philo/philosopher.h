/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 23:49:38 by ccambium          #+#    #+#             */
/*   Updated: 2022/08/24 11:57:46 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_philo
{
	pthread_t		thread;
	long long int	times_eat;
	size_t			n;
	char			forks[2];
	suseconds_t		lasteat;
	pthread_mutex_t	m;
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
	size_t			nb_philo;
	suseconds_t		time_die;
	suseconds_t		time_eat;
	suseconds_t		time_sleep;
	suseconds_t		start_time;
	long long int	times_to_eat;
	short			end;
	pthread_mutex_t	*end_mutex;
	pthread_mutex_t	*forks;
	pthread_mutex_t	time;
	char			*b_fork;
	t_obj			*o_head;
	t_philo			*p_head;
}	t_philosopher;

typedef struct s_package
{
	t_philo			*philo;
	t_philosopher	*philosopher;
}	t_package;

char				ft_isdigit(int c);
char				is_all_digit(char *str);
char				finish(t_philosopher *philo);
char				is_end(t_philosopher *philo);
char				init_philos(t_philosopher *philo);
char				eat(t_philosopher *philo, t_philo *p);
char				start(t_philosopher *philo, t_philo *head);
char				take_forks(t_philosopher *philo, t_philo *p);
char				check_forks(t_philosopher *philo, t_philo *p);
char				check_death(t_philosopher *philo, t_philo *p);
char				verification(t_philosopher *philo, char **av, int ac);

void				death(t_philo *p, t_philosopher *philo);
void				eating(t_philo *p, t_philosopher *philo);
void				sleeping(t_philo *p, t_philosopher *philo);
void				thinking(t_philo *p, t_philosopher *philo);
void				ft_info(const char *s);
void				ft_error(const char *s);
void				taking_fork(t_philo *p, t_philosopher *philo);
void				end(t_philosopher *philo);
void				free_all(t_philosopher *philo);
void				add_end_obj(t_obj *head, t_obj *obj);
void				die(t_philosopher *philo, t_philo *p);
void				think(t_philosopher *philo, t_philo *p);
void				ft_free(void *ptr, t_philosopher *philo);
char				p_sleep(t_philosopher *philo, t_philo *p);
void				abort_philo(t_philosopher *philo, size_t n);
void				release_forks(t_philosopher *philo, t_philo *p);

void				*routine(void *arg);
void				*ft_malloc(size_t size, t_philosopher *philo);

size_t				ft_strlen(const char *s);

suseconds_t			get_time(void);
suseconds_t			will_die(t_philosopher *philo, t_philo *p, long long int t);

long unsigned		ft_atolu(const char *nptr);

long long unsigned	ft_atollu(const char *nptr);

#endif
