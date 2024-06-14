/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshatra <rshatra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 07:56:26 by rshatra           #+#    #+#             */
/*   Updated: 2024/06/14 20:50:56 by rshatra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>

# define SIZE 800

typedef struct s_complex
{
	double			re;
	double			im;
}	t_complex;

typedef struct s_fractol
{
	const char		*name;
	mlx_image_t		*mlx_img;
	mlx_t			*mlx;
	t_complex		c;
}	t_fractol;

int					ft_strncmp(const char *str1, const char *str2, size_t x);
double				ft_atof(const char *str);
void				init_julia(t_fractol *fractol, char *s1, char *s2);
void				init_mandelbrot(t_fractol *fractol);
int					init(t_fractol *fractol);

#endif
