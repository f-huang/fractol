/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_mouse_hook.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 21:02:12 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/21 10:59:21 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>

#include <stdio.h>
#include "mlx.h"
#include "fract_ol.h"
#include "libft.h"

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
		[SCROLL_WHEEL_ZOOM_IN] = zoom_in
		// [SCROLL_WHEEL_ZOOM_OUT] = zoom_out
	};

	ft_printf("button: %i / (%i,%i)\n", button_code, x, y);
	if (x > 0 && y > 0 && button_code == SCROLL_WHEEL_ZOOM_IN)
		// || button_code == SCROLL_WHEEL_ZOOM_OUT)
	{
			mlx_clear_window(e->mlx, e->win);
			mlx_destroy_image(e->mlx, e->mlx_img.img);
			button_actions[button_code](e, x, y);
			fract_ol_create_image(e);
	}
	return (0);
}
