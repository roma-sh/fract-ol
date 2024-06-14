/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshatra <rshatra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:18:18 by rshatra           #+#    #+#             */
/*   Updated: 2024/06/14 20:46:52 by rshatra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if (argc == 4 && !ft_strncmp(argv[1], "julia", 5))
	{
		init_julia(&fractol, argv[2], argv[3]);
	}
	else if (argc == 2 && !ft_strncmp(argv[1], "mandelbort", 10))
	{
		init_mandelbrot(&fractol);
	}
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
	mlx_loop(fractol.mlx);
	mlx_terminate(fractol.mlx);
	return (0);
}
