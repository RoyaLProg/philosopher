/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 19:12:55 by ccambium          #+#    #+#             */
/*   Updated: 2022/07/08 20:16:08 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_error(const char *s)
{
	write(2, "ERROR : ", 8);
	write(2, s, ft_strlen(s));
	write(2, "\n", 1);
	exit(1);
}

void	ft_info(const char *s)
{
	write(1, "Philosopher : ", 14);
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
}
