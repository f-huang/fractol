/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_mouse_hook.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 21:02:12 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/29 18:47:10 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fract_ol.h"

int		fract_ol_mouse_hook(int button_code, int x, int y, t_env *e)
{
	static void		((*button_actions[])(t_env *e, int x, int y)) = {
		[SCROLL_WHEEL_ZOOM_IN] = zoom_in,
		[SCROLL_WHEEL_ZOOM_OUT] = zoom_out
	};

	if (x > 0 && y > 0 && (button_code == SCROLL_WHEEL_ZOOM_IN
		|| button_code == SCROLL_WHEEL_ZOOM_OUT))
	{
		mlx_clear_window(e->mlx, e->win);
		mlx_destroy_image(e->mlx, e->mlx_img.img);
		button_actions[button_code](e, x, y);
		fract_ol_create_image(e);
	}
	return (0);
}
