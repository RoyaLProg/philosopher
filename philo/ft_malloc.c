/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 22:43:45 by ccambium          #+#    #+#             */
/*   Updated: 2022/07/07 18:31:28 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

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
	if (philo->o_head != NULL)
		add_end_list(philo->o_head, obj);
	else
		philo->o_head = obj;
	return (ptr);
}

void	free_all(t_philosopher *philo)
{
	t_obj	*x;
	t_obj	*next;

	x = philo->o_head;
	while (x != NULL)
	{
		free(x->ptr);
		next = x->next;
		free(x);
		x = next;
	}
}

void	ft_free(void *ptr, t_philosopher *philo)
{
	t_obj	*x;
	t_obj	*last;

	last = NULL;
	x = philo->o_head;
	while (x != NULL)
	{
		if (x->ptr == ptr)
		{
			free(ptr);
			break ;
		}
		last = x;
		x = x->next;
	}
	if (x == NULL)
		return ;
	last->next = x->next;
	free(x);
}
