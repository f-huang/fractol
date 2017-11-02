/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_key_hook.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 23:07:06 by fhuang            #+#    #+#             */
/*   Updated: 2017/11/02 12:03:36 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fract_ol.h"
#include <stdio.h>

static int	is_in_keyhook(int keycode)
{
	return (keycode == ESC || keycode == ARROW_LEFT || keycode == ARROW_RIGHT
		|| keycode == ARROW_UP || keycode == ARROW_DOWN
		|| keycode == KEY_L || keycode == KEY_C || keycode == KEY_N
		|| keycode == KEY_P);
}

static void	next_fractal(t_env *e)
{
	e->index++;
	if (e->index == e->number_of_fractals)
		e->index = 0;
}

static void	previous_fractal(t_env *e)
{
	e->index--;
	if (e->index < 0)
		e->index = e->number_of_fractals - 1;
}

int		fract_ol_key_hook(int keycode, t_env *e)
{
	static void		((*key_actions[])(t_env *)) = {
		[ESC] = fract_ol_quit,
		[ARROW_LEFT] = translate_left,
		[ARROW_RIGHT] = translate_right,
		[ARROW_UP] = translate_up,
		[ARROW_DOWN] = translate_down,
		[KEY_L] = lock_image,
		[KEY_C] = change_color,
		[KEY_N] = next_fractal,
		[KEY_P] = previous_fractal
	};
	if (is_in_keyhook(keycode))
	{
		if (keycode != ESC && keycode != KEY_L)
		{
			mlx_clear_window(e->mlx, e->win);
			mlx_destroy_image(e->mlx, e->mlx_img.img);
		}
		key_actions[keycode](e);
		if (keycode != ESC && keycode != KEY_L)
			fract_ol_create_image(e);
	}
	return (0);
}
