/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_mouse_hook.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 21:02:12 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/20 23:37:54 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mlx.h"
#include "fract_ol.h"
#include "libft.h"

static void zoom_in(t_env *e, int x, int y)
{
	mlx_clear_window(e->mlx, e->win);
	mlx_destroy_image(e->mlx, e->mlx_img.img);

	e->mlx_img.fractal.zoom += 80;
	double x_percent_in_win = x / e->mlx_img.width;
	double coord_x = x_percent_in_win * get_distance(e->mlx_img.fractal.abscissa.max, e->mlx_img.fractal.abscissa.min) - ft_abs(e->mlx_img.fractal.abscissa.min);
	double new_width = e->mlx_img.width / e->mlx_img.fractal.zoom;
	e->mlx_img.fractal.abscissa.min = coord_x - x_percent_in_win * new_width;
	e->mlx_img.fractal.abscissa.max = e->mlx_img.fractal.abscissa.min + e->mlx_img.fractal.abscissa.min;

	double y_percent_in_win = y / e->mlx_img.height;
	double coord_y = y_percent_in_win * get_distance(e->mlx_img.fractal.ordinate.max, e->mlx_img.fractal.ordinate.min) - ft_abs(e->mlx_img.fractal.ordinate.min);
	double new_height = e->mlx_img.height / e->mlx_img.fractal.zoom;
	e->mlx_img.fractal.ordinate.min = coord_y - y_percent_in_win * new_height;
	e->mlx_img.fractal.ordinate.max = e->mlx_img.fractal.ordinate.min + new_height;
	printf("x - y : %lf , %lf\n", coord_x, coord_y);
	printf("click x - y : %lf , %lf\n", x_percent_in_win * new_width, y_percent_in_win * new_height);
	printf("new x - y : %lf , %lf\n", new_width, new_height);
	printf("min x - y : %lf, %lf\n", e->mlx_img.fractal.abscissa.min, e->mlx_img.fractal.ordinate.min);
	fract_ol_create_image(e);
}
//
// static void zoom_out(t_env *e, int x, int y)
// {
// 	(void)x;
// 	(void)y;
// 	mlx_clear_window(e->mlx, e->win);
// 	mlx_destroy_image(e->mlx, e->mlx_img.img);
// 	e->mlx_img.fractal.zoom -= 20;
// 	if (e->mlx_img.fractal.zoom < 20)
// 		e->mlx_img.fractal.zoom = 20;
// 	fract_ol_create_image(e);
// }


int		fract_ol_mouse_hook(int button_code, int x, int y, t_env *e)
{
	static void		((*button_actions[])(t_env *e, int x, int y)) = {
		[LEFT_CLICK] = zoom_in
		// [SCROLL_WHEEL_ZOOM_OUT] = zoom_out
	};

	ft_printf("button: %i / (%i,%i)\n", button_code, x, y);
	if (x > 0 && y > 0 && button_code == LEFT_CLICK)
		// || button_code == SCROLL_WHEEL_ZOOM_OUT)
	{
		button_actions[button_code](e, x, y);
	}
	return (0);
}
