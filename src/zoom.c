/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 10:54:52 by fhuang            #+#    #+#             */
/*   Updated: 2017/11/02 14:19:35 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fract_ol.h"

#define STEP 800

#define SMALL_ZOOM 1.2
#define BIG_ZOOM 1.5

#define SMALL_ITERATIONS 1.01
#define BIG_ITERATIONS 1.2

static void	zoom_calculate(t_env *e, const int x, const int y)
{
	double	x_percent_in_win;
	double	y_percent_in_win;
	double	new_size;

	x_percent_in_win = x / e->mlx_img.size;
	y_percent_in_win = y / e->mlx_img.size;
	new_size = e->mlx_img.size / e->fractals[e->index].zoom;
	e->fractals[e->index].abscissa.min = x_percent_in_win * get_distance(\
		e->fractals[e->index].abscissa.max, e->fractals[e->index].abscissa.min)
		+ e->fractals[e->index].abscissa.min - x_percent_in_win * new_size;
	e->fractals[e->index].abscissa.max =
		e->fractals[e->index].abscissa.min + new_size;
	e->fractals[e->index].ordinate.min = y_percent_in_win * get_distance(\
		e->fractals[e->index].ordinate.max, e->fractals[e->index].ordinate.min)
		+ e->fractals[e->index].ordinate.min - y_percent_in_win * new_size;
	e->fractals[e->index].ordinate.max =
		e->fractals[e->index].ordinate.min + new_size;
}

void		zoom_in(t_env *e, const int x, const int y)
{
	if (e->fractals[e->index].zoom < STEP)
	{
		e->fractals[e->index].iteration *= SMALL_ITERATIONS;
		e->fractals[e->index].zoom *= SMALL_ZOOM;
	}
	else
	{
		if (e->fractals[e->index].iteration < MAX_ITERATIONS)
			e->fractals[e->index].iteration *= BIG_ITERATIONS;
		e->fractals[e->index].zoom *= BIG_ZOOM;
	}
	zoom_calculate(e, x, y);
}

void		zoom_out(t_env *e, const int x, const int y)
{
	if (e->fractals[e->index].zoom > 150)
	{
		if (e->fractals[e->index].zoom < STEP)
			e->fractals[e->index].zoom /= SMALL_ZOOM;
		else
			e->fractals[e->index].zoom /= BIG_ZOOM;
	}
	e->fractals[e->index].iteration /= SMALL_ITERATIONS;
	zoom_calculate(e, x, y);
}
