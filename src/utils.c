/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshatra <rshatra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 07:56:46 by rshatra           #+#    #+#             */
/*   Updated: 2024/06/14 20:15:27 by rshatra          ###   ########.fr       */
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

double	ft_atof(const char *str)
{
	double	res;
	double	sign;
	double	after_dot;

	res = 0;
	sign = 1;
	after_dot = 0;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str && *str != '.')
		res = res * 10 + *str++ - '0';
	if (*str == '.')
	{
		str++;
		while (*str)
		{
			after_dot = after_dot * 10 + *str - '0';
			str++;
		}
	}
	return (res + after_dot / 10);
}
