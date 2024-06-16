/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshatra <rshatra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 07:56:26 by rshatra           #+#    #+#             */
/*   Updated: 2024/06/17 00:28:57 by rshatra          ###   ########.fr       */
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
# define MAX_ITE 50
# define STEP 12

typedef struct s_pixel
{
	int32_t		w;
	int32_t		h;
	uint32_t	color;
}	t_pixel;

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
	t_complex		b;
	unsigned int	(*f)(struct s_fractol *fractol, t_complex *c);
	double			factor;
	double			axis_len;
	uint32_t		max_iter;
	int				rgb[3];
	int				color_shift;
}	t_fractol;

int					ft_strncmp(const char *str1, const char *str2, size_t x);
double				ft_atof(const char *s);
void				init_julia(t_fractol *fractol, char *s1, char *s2);
void				init_mandelbrot(t_fractol *fractol);
int					init(t_fractol *fractol);
void				ztrans(t_complex *z, t_fractol *fractol, t_pixel *pixel);
uint32_t			julia_set(t_fractol *fractol, t_complex *c);
uint32_t			mandelbrot_set(t_fractol *fractol, t_complex *c);
int32_t				bernstein_color(double x, int *rgb);
int32_t				pixel_color(int32_t r, int32_t g, int32_t b, int32_t a);
void				draw(void *param);
void				zoom(double xdelta, double ydelta, void *param);
void				keyboard_control(void *param);
void				color_shift(t_fractol *fr);
#endif
