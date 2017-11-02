/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_key_hook.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 23:07:06 by fhuang            #+#    #+#             */
/*   Updated: 2017/11/02 17:23:36 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fract_ol.h"

static void	lock_image(t_env *e)
{
	e->state ^= IMAGE_LOCK;
}

static void	change_color(t_env *e)
{
	if (e->mlx_img.color != F_BLUE)
		e->mlx_img.color += (enum e_fractal_color)1;
	else
		e->mlx_img.color = F_BW;
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

int			fract_ol_key_hook(int keycode, t_env *e)
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
		[KEY_P] = previous_fractal,
		[KEY_R] = reset_parameters
	};

	keycode == KEY_L ? key_actions[keycode](e) : 0;
	if (keycode == ESC || keycode == ARROW_LEFT || keycode == ARROW_RIGHT
		|| keycode == ARROW_UP || keycode == ARROW_DOWN || keycode == KEY_C
		|| keycode == KEY_N || keycode == KEY_P || keycode == KEY_R)
	{
		mlx_clear_window(e->mlx, e->win);
		mlx_destroy_image(e->mlx, e->mlx_img.img);
		key_actions[keycode](e);
		fract_ol_create_image(e);
	}
	return (0);
}
