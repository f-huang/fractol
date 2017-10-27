/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 23:31:35 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/27 16:08:59 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fract_ol.h"
#include "libft.h"
#include "X11/X.h"
#include <stdio.h>

#define WINDOW_NAME "fract_ol"

static void	fract_ol_init_fractal_param(t_fractal *fractal)
{
	if (fractal->type == MANDELBROT)
	{
		fractal->abscissa = (t_range) { .min = MANDELBROT_X1, .max = MANDELBROT_X2 };
		fractal->ordinate = (t_range) { .min = MANDELBROT_Y1, .max = MANDELBROT_Y2 };
		fractal->zoom = (IMAGE_SIZE / get_distance(fractal->ordinate.max, fractal->ordinate.min)\
			+ IMAGE_SIZE / get_distance(fractal->abscissa.max, fractal->abscissa.min)) / 2 - IMAGE_SIZE * 0.02;
	}
	else if (fractal->type == JULIA)
	{
		fractal->motion_complex = (t_complex) { .real = JULIA_INITIAL_REAL, .imaginary = JULIA_INITIAL_IMAGINARY };
		fractal->abscissa = (t_range) { .min = JULIA_X1, .max = JULIA_X2 };;
		fractal->ordinate = (t_range) { .min = JULIA_Y1, .max = JULIA_Y2 };
		fractal->zoom = (IMAGE_SIZE / get_distance(fractal->ordinate.max, fractal->ordinate.min)\
			+ IMAGE_SIZE / get_distance(fractal->abscissa.max, fractal->abscissa.min)) / 2 - IMAGE_SIZE * 0.02;
	}
	fractal->iteration = ITERATIONS;
	printf("%Lf\n", fractal->zoom);
}

int		main(int ac, char **av)
{
	t_env	e;

	ft_bzero(&e, sizeof(t_env));
	if (ac < 2)
		return (-fract_ol_error("Not enough parameters"));
	if ((int)(e.mlx_img.fractal.type = fract_ol_name_to_type(av[1])) == -1)
		return (-fract_ol_error("Wrong parameters"));
	if (!(e.mlx = mlx_init()))
		return (-fract_ol_error("Could not init mlx."));
	if (!(e.win = mlx_new_window(e.mlx, IMAGE_SIZE, IMAGE_SIZE, WINDOW_NAME)))
		return (-fract_ol_error("Could not create a new window."));
	e.mlx_img.size = IMAGE_SIZE;
	pthread_mutex_init(&e.mutex, NULL);

	fract_ol_init_fractal_param(&e.mlx_img.fractal);
	if (!fract_ol_create_image(&e))
		return (-fract_ol_error("An error occured during the image creation."));
	mlx_hook(e.win, ButtonPress, ButtonPressMask, fract_ol_mouse_hook, &e);
	mlx_hook(e.win, KeyPress, KeyPressMask, fract_ol_key_hook, &e);
	mlx_hook(e.win, MotionNotify, PointerMotionMask, fract_ol_motion_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
