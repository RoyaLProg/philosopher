/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atolu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 05:19:34 by ccambium          #+#    #+#             */
/*   Updated: 2022/08/14 05:19:34 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static long unsigned	ft_atolu_part2(int i, int minus, const char *nptr)
{
	long unsigned	v;

	v = 0;
	while (*(nptr + i) && ft_isdigit(*(nptr + i)))
	{
		v *= 10;
		v += *(nptr + i) - '0';
		i++;
	}
	if (minus)
		v *= -1;
	return (v);
}

long unsigned	ft_atolu(const char *nptr)
{
	int	i;
	int	minus;

	i = 0;
	minus = 0;
	while (*(nptr + i) == '\f' || *(nptr + i) == '\n' || *(nptr + i) == '\r'
		|| *(nptr + i) == '\t' || *(nptr + i) == '\v' || *(nptr + i) == ' ')
		i++;
	if (*(nptr + i) == '-')
	{
		i++;
		minus = 1;
	}
	else if (*(nptr + i) == '+')
		i++;
	return (ft_atolu_part2(i, minus, nptr));
}
