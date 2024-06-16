/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshatra <rshatra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 18:26:04 by rshatra           #+#    #+#             */
/*   Updated: 2024/06/17 00:26:18 by rshatra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	keyboard_control(void *param)
{
	t_fractol	*fractal;

	fractal = param;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fractal->mlx);
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_SPACE))
		color_shift(fractal);
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_UP))
		fractal->b.im -= fractal->factor * STEP;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_DOWN))
		fractal->b.im += fractal->factor * STEP;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_RIGHT))
		fractal->b.re += fractal->factor * STEP;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_LEFT))
		fractal->b.re -= fractal->factor * STEP;
}

void	zoom(double xdelta, double ydelta, void *param)
{
	t_fractol	*fractal;
	t_pixel		pixel;
	t_complex	cursor;
	t_complex	d;

	xdelta = 0;
	fractal = param;
	mlx_get_mouse_pos(fractal->mlx, &pixel.w, &pixel.h);
	ztrans(&cursor, fractal, &pixel);
	d.re = cursor.re - fractal->b.re;
	d.im = fractal->b.im - cursor.im;
	if (ydelta > 0)
	{
		fractal->axis_len *= 0.9;
		fractal->b.re += d.re / 10;
		fractal->b.im -= d.im / 10;
	}
	else if (ydelta < 0)
	{
		fractal->axis_len *= 1.1;
		fractal->b.re -= d.re / 10;
		fractal->b.im += d.im / 10;
	}
	fractal->factor = fractal->axis_len / SIZE;
}

void	color_shift(t_fractol *fr)
{
	int	tmp;

	fr->color_shift++;
	if (fr->color_shift > 1)
		fr->color_shift = 0;
	tmp = fr->rgb[fr->color_shift];
	fr->rgb[fr->color_shift] = fr->rgb[fr->color_shift + 1];
	fr->rgb[fr->color_shift + 1] = tmp;
}
