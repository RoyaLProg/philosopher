/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_end_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 21:08:38 by ccambium          #+#    #+#             */
/*   Updated: 2022/07/02 21:28:11 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	add_end_obj(t_obj *head, t_obj *obj)
{
	t_obj	*x;

	x = head;
	while (x->next != NULL)
		x = x->next;
	x->next = obj;
}
