/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_key_hook.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 23:07:06 by fhuang            #+#    #+#             */
/*   Updated: 2017/11/03 14:47:00 by fhuang           ###   ########.fr       */
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
	if (e->mlx_img.color != (enum e_fractal_color)(NB_COLORS - 1))
		e->mlx_img.color += (enum e_fractal_color)1;
	else
		e->mlx_img.color = (enum e_fractal_color)0;
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

int			fract_ol_key_hook(int key, t_env *e)
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
		[KEY_R] = reset_parameters,
		[KEY_I] = add_iteration
	};

	key == KEY_L ? key_actions[key](e) : 0;
	if (key == ARROW_UP || key == ARROW_LEFT || key == ARROW_RIGHT
		|| key == ARROW_DOWN || key == KEY_C || key == KEY_N
		|| key == KEY_P || key == KEY_R || key == ESC || key == KEY_I)
	{
		mlx_clear_window(e->mlx, e->win);
		mlx_destroy_image(e->mlx, e->mlx_img.img);
		key_actions[key](e);
		fract_ol_create_image(e);
	}
	return (0);
}
