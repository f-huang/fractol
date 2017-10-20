/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 23:31:35 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/20 18:09:44 by fhuang           ###   ########.fr       */
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
		fractal->abscissa = (t_range) { .min = -2.1, .max = 0.6 };
		fractal->ordinate = (t_range) { .min = -1.2, .max = 1.2 };
		fractal->x = fractal->abscissa.min;
		fractal->y = fractal->ordinate.min;
		fractal->zoom = (IMAGE_HEIGHT / get_distance(fractal->ordinate.max, fractal->ordinate.min)\
			+ IMAGE_WIDTH / get_distance(fractal->abscissa.max, fractal->abscissa.min)) / 2 - IMAGE_WIDTH * 0.02;
		// fractal->zoom = 200;
	}
	printf("%lf\n", fractal->zoom);
	fractal->iteration = 300;
}

int		main(int ac, char **av)
{
	t_env	e;

	ft_bzero(&e, sizeof(t_env));
	if (!(e.mlx = mlx_init()))
		return (-fract_ol_error("Could not init mlx."));
	if (!(e.win = mlx_new_window(e.mlx, IMAGE_WIDTH, IMAGE_HEIGHT, WINDOW_NAME)))
		return (-fract_ol_error("Could not create a new window."));
	e.mlx_img.fractal.type = fract_ol_name_to_type("Mandelbrot");

	fract_ol_init_fractal_param(&e.mlx_img.fractal);
	if (!fract_ol_create_image(&e))
		return (-fract_ol_error("An error occured during the image creation."));
	// mlx_mouse_hook(e.win, fract_ol_mouse_hook, &e);
	mlx_hook(e.win, ButtonPress, ButtonPressMask, fract_ol_mouse_hook, &e);
	mlx_hook(e.win, KeyPress, KeyPressMask, fract_ol_key_hook, &e);
	mlx_loop(e.mlx);
	(void)ac;
	(void)av;
	return (0);
}
