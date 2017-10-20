/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_mouse_hook.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 21:02:12 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/20 18:47:21 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mlx.h"
#include "fract_ol.h"
#include "libft.h"

static void zoom_in(t_env *e, int x, int y)
{
	static double	coef_width = 0;
	static double	coef_height = 0;
	double			new_width;

	if (!coef_width)
		coef_width = e->mlx_img.width / get_distance(e->mlx_img.fractal.abscissa.max, e->mlx_img.fractal.abscissa.min);
	if (!coef_height)
		coef_height = e->mlx_img.height / get_distance(e->mlx_img.fractal.ordinate.max, e->mlx_img.fractal.ordinate.min);
	(void)x;
	(void)y;
	mlx_clear_window(e->mlx, e->win);
	mlx_destroy_image(e->mlx, e->mlx_img.img);
	e->mlx_img.fractal.zoom += 80;
	new_width = e->mlx_img.width / e->mlx_img.fractal.zoom;
	e->mlx_img.fractal.x = x / coef_width - new_width / 2 + e->mlx_img.fractal.abscissa.min;
	// e->mlx_img.fractal.x = x / coef_width + e->mlx_img.fractal.abscissa.min + e->mlx_img.fractal.x;
	// e->mlx_img.fractal.y = y / coef_height - ft_abs(e->mlx_img.fractal.y);
	// e->mlx_img.fractal.zoom = (e->mlx_img.height / get_distance(e->mlx_img.fractal.ordinate.max, e->mlx_img.fractal.ordinate.min)\
	// 	+ e->mlx_img.width / get_distance(e->mlx_img.fractal.abscissa.max, e->mlx_img.fractal.abscissa.min)) / 2 - e->mlx_img.width * 0.02;;
	printf("%lf -> x : %lf = %lf - %lf\n", e->mlx_img.fractal.zoom, e->mlx_img.fractal.x, x /coef_width, new_width / 2);
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
	if (button_code == LEFT_CLICK)
		// || button_code == SCROLL_WHEEL_ZOOM_OUT)
	{
		button_actions[button_code](e, x, y);
	}
	return (0);
}
