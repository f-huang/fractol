/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_motion_hook.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 13:12:26 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/27 14:02:43 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mlx.h"
#include "fract_ol.h"

int	fract_ol_motion_hook(int x, int y, t_env *e)
{
	static long long		start_rendering = 0;
	double	x_percent_in_win;
	double	y_percent_in_win;

	if (e->mlx_img.fractal.type != JULIA)
		return (0);

	start_rendering = get_timestamp();
	mlx_clear_window(e->mlx, e->win);
	mlx_destroy_image(e->mlx, e->mlx_img.img);x_percent_in_win = x / e->mlx_img.size;
	y_percent_in_win = y / e->mlx_img.size;
	e->mlx_img.fractal.motion_complex = (t_complex) {
		.real = x_percent_in_win * get_distance(
			e->mlx_img.fractal.abscissa.max, e->mlx_img.fractal.abscissa.min),
		.imaginary = y_percent_in_win * get_distance(
			e->mlx_img.fractal.ordinate.max, e->mlx_img.fractal.ordinate.min)
	};
	fract_ol_create_image(e);
	millisleep(start_rendering + 1000 / FPS - get_timestamp());
	// (void)x;
	// (void)y;
	return (0);
}
