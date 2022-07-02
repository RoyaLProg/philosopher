/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 22:43:45 by ccambium          #+#    #+#             */
/*   Updated: 2022/07/02 21:14:16 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philosopher.h"

typedef struct s_obj
{
	void	*ptr;
	void	*next;
}	t_obj;

void	*ft_malloc(size_t size, t_philosopher	*philo)
{
	void	*ptr;
	t_obj	*obj;

	ptr = malloc(size);
	if (ptr == NULL)
		return (NULL);
	obj = malloc(sizeof(t_obj));
	if (obj == NULL)
	{
		free(ptr);
		return (NULL);
	}
	obj->ptr = ptr;
	obj->next = NULL;
	if (philo->head_malloc != NULL)
		add_end_list(philo->head_malloc, obj);
	else
		philo->head_malloc = obj;
	return (ptr);
}

void	free_all(t_philosopher *philo)
{
	t_obj	*x;
	t_obj	*next;

	x = philo->head_malloc;
	while (x != NULL)
	{
		free(x->ptr)
		next = x->next;
		free(x);
		x = next;
	}
}
