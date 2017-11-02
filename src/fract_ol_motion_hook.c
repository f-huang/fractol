/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_motion_hook.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 13:12:26 by fhuang            #+#    #+#             */
/*   Updated: 2017/11/02 17:34:51 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fract_ol.h"

int	fract_ol_motion_hook(int x, int y, t_env *e)
{
	double				x_percent_in_win;
	double				y_percent_in_win;

	if (e->fractals[e->index].type != JULIA || e->state & IMAGE_LOCK)
		return (0);
	mlx_clear_window(e->mlx, e->win);
	mlx_destroy_image(e->mlx, e->mlx_img.img);
	x_percent_in_win = x / e->mlx_img.size;
	y_percent_in_win = y / e->mlx_img.size;
	e->fractals[e->index].motion_complex = (t_complex) {
		.real = x_percent_in_win,
		.imaginary = y_percent_in_win
	};
	fract_ol_create_image(e);
	return (0);
}
