/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_mouse_hook.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 21:02:12 by fhuang            #+#    #+#             */
/*   Updated: 2017/04/22 15:58:04 by FannyHuang       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fract_ol.h"
#include "libft.h"

int		fract_ol_mouse_hook(int button, int x, int y, void *param)
{
	ft_printf("button: %i / (%i,%i)\n", button, x, y);
	if (button == SCROLL_WHEEL_ZOOM_IN)
	{
		mlx_clear_window(((t_env*)param)->mlx, ((t_env*)param)->win);
		mlx_destroy_image(((t_env*)param)->mlx, ((t_env*)param)->mlx_img.img);
		((t_env*)param)->mlx_img.fractal.zoom += 20;
		((t_env*)param)->mlx_img.fractal.coord[0] = -x / 100;
		((t_env*)param)->mlx_img.fractal.coord[2] = -y / 100;
		fract_ol_create_image((t_env*)param);
	}
	else if (button == SCROLL_WHEEL_ZOOM_OUT)
	{
		mlx_clear_window(((t_env*)param)->mlx, ((t_env*)param)->win);
		mlx_destroy_image(((t_env*)param)->mlx, ((t_env*)param)->mlx_img.img);
		((t_env*)param)->mlx_img.fractal.zoom -= 20;
		if (((t_env*)param)->mlx_img.fractal.zoom < 20)
			((t_env*)param)->mlx_img.fractal.zoom = 20;
		fract_ol_create_image((t_env*)param);
	}
	return (0);
}
