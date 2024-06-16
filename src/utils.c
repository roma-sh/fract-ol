/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshatra <rshatra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 07:56:46 by rshatra           #+#    #+#             */
/*   Updated: 2024/06/16 04:26:50 by rshatra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *str1, const char *str2, size_t x)
{
	if (x == 0)
		return (0);
	while (*str1 && *str2 && *str1 == *str2 && x > 1)
	{
		str1++;
		str2++;
		x--;
	}
	return ((unsigned char)(*str1) - (unsigned char)(*str2));
}

double	ft_atof(const char *s)
{
	long	before_dot;
	double	after_dot;
	double	pow;
	int		sign;

	before_dot = 0;
	after_dot = 0;
	sign = +1;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		++s;
	while ('+' == *s || '-' == *s)
		if ('-' == *s++)
			sign = -sign;
	while (*s != '.' && *s)
		before_dot = (before_dot * 10) + (*s++ - 48);
	if ('.' == *s)
		++s;
	while (*s)
	{
		pow /= 10;
		after_dot = after_dot + (*s++ - 48) * pow;
	}
	return ((before_dot + after_dot) * sign);
}
