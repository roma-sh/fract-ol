/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshatra <rshatra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:18:18 by rshatra           #+#    #+#             */
/*   Updated: 2024/06/16 04:06:47 by rshatra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw(void *param)
{
	t_fractol	*fractal;
	t_pixel		pixel;
	t_complex	z;

	fractal = param;
	pixel.h = 0;
	while (pixel.h < SIZE)
	{
		pixel.w = 0;
		while (pixel.w < SIZE)
		{
			ztrans(&z, fractal, &pixel);
			pixel.color = fractal->f(fractal, &z);
			mlx_put_pixel(fractal->mlx_img, pixel.w, pixel.h, pixel.color);
			pixel.w++;
		}
		pixel.h++;
	}
}

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if (argc == 4 && !ft_strncmp(argv[1], "julia", 5))
		init_julia(&fractol, argv[2], argv[3]);
	else if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		init_mandelbrot(&fractol);
	else
	{
		write(1, "please choose the correct fractol:\n", 35);
		write(1, "\t./fractol \"mandelbrot\"\n", 24);
		write(1, "\t./fractol \"julia\" <param1> <param2>\n", 37);
		exit(EXIT_FAILURE);
	}
	if (init(&fractol) == 1)
	{
		write(1, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	mlx_loop_hook(fractol.mlx, draw, &fractol);
	mlx_loop(fractol.mlx);
	mlx_terminate(fractol.mlx);
	return (0);
}
