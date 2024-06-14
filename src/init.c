/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshatra <rshatra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 19:49:42 by rshatra           #+#    #+#             */
/*   Updated: 2024/06/14 20:44:37 by rshatra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_julia(t_fractol *fractol, char *s1, char *s2)
{
	fractol->c.re = ft_atof(s1);
	fractol->c.im = ft_atof(s2);
	fractol->name = "julia";
}

void	init_mandelbrot(t_fractol *fractol)
{
	fractol->name = "mandelbrot";
}

int	init(t_fractol *fractol)
{
	fractol->mlx = mlx_init(SIZE, SIZE, fractol->name, false);
	if (!fractol->mlx)
		return (1);
	fractol->mlx_img = mlx_new_image(fractol->mlx, SIZE, SIZE);
	if (!fractol->mlx_img)
	{
		mlx_close_window(fractol->mlx);
		return (1);
	}
	if (mlx_image_to_window(fractol->mlx, fractol->mlx_img, 0, 0) == -1)
	{
		mlx_close_window(fractol->mlx);
		return (1);
	}
	return (0);
}
