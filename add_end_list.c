/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_end_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 21:08:38 by ccambium          #+#    #+#             */
/*   Updated: 2022/07/04 01:21:23 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	add_end_obj(t_obj *head, t_obj *obj)
{
	t_obj	*x;

	x = head;
	while (x->next != NULL)
		x = x->next;
	x->next = obj;
}

void	add_end_philo(t_philo *head, t_philo *obj)
{
	t_philo	*x;

	x = head;
	while (x->next != NULL)
		x = x->next;
	x->next = obj;
}
