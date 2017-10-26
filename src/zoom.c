/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 10:54:52 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/26 18:35:08 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fract_ol.h"
#include <stdio.h>

#define STEP 800

#define SMALL_ZOOM 200
#define BIG_ZOOM 1.5

#define SMALL_ITERATIONS 1.01
#define BIG_ITERATIONS 1.2

static void	zoom_calculate(t_env *e, const int x, const int y)
{
	double	x_percent_in_win;
	double	y_percent_in_win;
	double	new_width;
	double	new_height;

	x_percent_in_win = x / e->mlx_img.width;
	new_width = e->mlx_img.width / e->mlx_img.fractal.zoom;
	e->mlx_img.fractal.abscissa.min = x_percent_in_win * get_distance(\
		e->mlx_img.fractal.abscissa.max, e->mlx_img.fractal.abscissa.min) -\
		ft_abs(e->mlx_img.fractal.abscissa.min) - x_percent_in_win * new_width;
	e->mlx_img.fractal.abscissa.max = e->mlx_img.fractal.abscissa.min + new_width;

	y_percent_in_win = y / e->mlx_img.height;
	new_height = e->mlx_img.height / e->mlx_img.fractal.zoom;
	e->mlx_img.fractal.ordinate.min = y_percent_in_win * get_distance(\
		e->mlx_img.fractal.ordinate.max, e->mlx_img.fractal.ordinate.min) -\
		ft_abs(e->mlx_img.fractal.ordinate.min) - y_percent_in_win * new_height;
	e->mlx_img.fractal.ordinate.max = e->mlx_img.fractal.ordinate.min + new_height;
}

void		zoom_in(t_env *e, const int x, const int y)
{
	if (e->mlx_img.fractal.zoom < STEP)
	{
		e->mlx_img.fractal.iteration *= SMALL_ITERATIONS;
		e->mlx_img.fractal.zoom += SMALL_ZOOM;
	}
	else
	{
		if (e->mlx_img.fractal.iteration < MAX_ITERATIONS)
			e->mlx_img.fractal.iteration *= BIG_ITERATIONS;
		e->mlx_img.fractal.zoom *= BIG_ZOOM;
	}
	zoom_calculate(e, x, y);
}

void		zoom_out(t_env *e, const int x, const int y)
{
	if (e->mlx_img.fractal.zoom > 200)
	{
		if (e->mlx_img.fractal.zoom < STEP)
			e->mlx_img.fractal.zoom -= SMALL_ZOOM;
		else
			e->mlx_img.fractal.zoom /= BIG_ZOOM;
	}
	e->mlx_img.fractal.iteration /= SMALL_ITERATIONS;
	zoom_calculate(e, x, y);
}
