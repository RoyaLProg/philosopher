/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 19:34:11 by ccambium          #+#    #+#             */
/*   Updated: 2022/07/08 19:47:29 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

suseconds_t	get_time(void)
{
	struct timeval	tv;
	suseconds_t		time;

	if (gettimeofday(&tv, NULL) != 0)
	{
		ft_error("Could not read time !");
		return (0);
	}
	time = (tv.tv_sec * 1000000 + tv.tv_usec) / 1000;
	return (time);
}
