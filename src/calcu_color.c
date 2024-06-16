/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcu_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshatra <rshatra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 02:09:35 by rshatra           #+#    #+#             */
/*   Updated: 2024/06/16 04:09:21 by rshatra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint32_t	julia_set(t_fractol *fractol, t_complex *c)
{
	uint32_t		color;
	double			tmp;
	unsigned int	i;

	i = 0;
	while (i < fractol->max_iter)
	{
		tmp = c->re * c->re - c->im * c->im;
		c->im = 2 * c->re * c->im + fractol->c.im;
		c->re = tmp + fractol->c.re;
		if (c->re * c->re + c->im * c->im > 4)
			break ;
		i++;
	}
	if (i == fractol->max_iter)
		color = pixel_color(0x00, 0x00, 0x00, 0xFF);
	else
		color = bernstein_color(1.0 * i / fractol->max_iter, fractol->rgb);
	return (color);
}

uint32_t	mandelbrot_set(t_fractol *fractol, t_complex *c)
{
	uint32_t		color;
	double			tmp;
	unsigned int	i;
	t_complex		z;

	i = 0;
	z.re = 0;
	z.im = 0;
	while (i < fractol->max_iter)
	{
		tmp = z.re * z.re - z.im * z.im + c->re;
		z.im = 2 * z.re * z.im + c->im;
		z.re = tmp;
		if (z.re * z.re + z.im * z.im > 4)
			break ;
		i++;
	}
	if (i == fractol->max_iter)
		color = pixel_color(0x00, 0x00, 0x00, 0xFF);
	else
		color = bernstein_color(1.0 * i / fractol->max_iter, fractol->rgb);
	return (color);
}

int32_t	bernstein_color(double x, int *rgb)
{
	int32_t	poly[3];

	poly[rgb[0]] = 255 * 15 * (1 - x) * (1 - x) * x * x;
	poly[rgb[1]] = 255 * 9 * (1 - x) * x * x * x;
	poly[rgb[2]] = 255 * 8.5 * (1 - x) * (1 - x) * (1 - x) * x;
	return (pixel_color(poly[0], poly[1], poly[2], 255));
}

void	ztrans(t_complex *z, t_fractol *fractal, t_pixel *pixel)
{
	z->re = (+1.0) * fractal->zoom * pixel->w + fractal->b.re;
	z->im = (-1.0) * fractal->zoom * pixel->h + fractal->b.im;
}

int32_t	pixel_color(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
