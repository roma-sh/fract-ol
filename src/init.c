/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshatra <rshatra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 19:49:42 by rshatra           #+#    #+#             */
/*   Updated: 2024/06/17 00:27:59 by rshatra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	init_julia(t_fractol *fractol, char *s1, char *s2)
{
	fractol->axis_len = 4.0;
	fractol->c.re = ft_atof(s1);
	fractol->c.im = ft_atof(s2);
	fractol->name = "julia";
	fractol->f = julia_set;
	fractol->factor = fractol->axis_len / SIZE;
	fractol->rgb[0] = 1;
	fractol->rgb[1] = 0;
	fractol->rgb[2] = 2;
	fractol->max_iter = MAX_ITE;
	fractol->b.re = 0.0 - fractol->axis_len / 2.0;
	fractol->b.im = 0.0 + fractol->axis_len / 2.0;
	fractol->color_shift = 0;
}

void	init_mandelbrot(t_fractol *fractol)
{
	fractol->axis_len = 4.0;
	fractol->name = "mandelbrot";
	fractol->f = mandelbrot_set;
	fractol->factor = fractol->axis_len / SIZE;
	fractol->rgb[0] = 1;
	fractol->rgb[1] = 0;
	fractol->rgb[2] = 2;
	fractol->max_iter = MAX_ITE;
	fractol->b.re = 0.0 - fractol->axis_len / 2.0;
	fractol->b.im = 0.0 + fractol->axis_len / 2.0;
	fractol->color_shift = 0;
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
