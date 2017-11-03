/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_create_image.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 00:50:55 by fhuang            #+#    #+#             */
/*   Updated: 2017/11/03 10:42:20 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "fract_ol.h"

#define STRING_KEY_L "L: lock image"
#define STRING_KEY_P "P: Previous fractal"
#define STRING_KEY_N "N: Next fractal"
#define STRING_KEY_R "R: Reset"
#define STRING_KEY_C "C: Change color"
#define STRING_KEY_ESC "ESC: Quit"
#define STRING_ARROWS "Arrows: Translate"
#define STRING_SCROLL "Scroll: Zoom in/out"

#define STR_PUT(x, y, str) mlx_string_put(e->mlx, e->win, x, y, 0xFFFFFF, str)

static void print_helper_strings(t_env *e)
{
	STR_PUT(10, 10, (char*)get_fractal_name(e->fractals[e->index].type));
	if (e->fractals[e->index].type == JULIA)
		STR_PUT(IMAGE_SIZE - 170, 10, STRING_KEY_L);
	STR_PUT(10, 50, STRING_KEY_P);
	STR_PUT(10, 70, STRING_KEY_N);
	STR_PUT(IMAGE_SIZE - 170, 40, STRING_KEY_C);
	STR_PUT(IMAGE_SIZE - 220, 80, STRING_ARROWS);
	STR_PUT(IMAGE_SIZE - 220, 100, STRING_SCROLL);
	STR_PUT(10, IMAGE_SIZE - 60, STRING_KEY_R);
	STR_PUT(10, IMAGE_SIZE - 30, STRING_KEY_ESC);
}

static void	fract_ol_draw_fractal(t_env *e)
{
	t_draw_helper	helper[NB_THREADS];
	unsigned int	tmp_x;
	int				j;

	j = -1;
	while (++j < e->nb_screen_cut)
	{
		tmp_x = e->screen_cut_size * (j + 1);
		helper[j] = (t_draw_helper) {
			.img = &e->mlx_img,
			.fractal = e->fractals[e->index],
			.offset = (t_offset) { .x = e->screen_cut_size * j, .y = 0 },
			.range = (t_offset) {
				.x = (tmp_x > e->mlx_img.size ? e->mlx_img.size : tmp_x),
				.y = e->mlx_img.size
			},
		};
		draw_corresponding_fractal(&helper[j], &e->thread[j]);
	}
	while (j >= 0)
		pthread_join(e->thread[j--], NULL);
}

int			fract_ol_create_image(t_env *e)
{
	if (!(e->mlx_img.img = mlx_new_image(
		e->mlx, (int)e->mlx_img.size, (int)e->mlx_img.size)))
		return (0);
	e->mlx_img.address = mlx_get_data_addr(e->mlx_img.img,\
		&e->mlx_img.bits_per_pixel, &e->mlx_img.size_line, &e->mlx_img.endian);
	fract_ol_draw_fractal(e);
	mlx_put_image_to_window(e->mlx, e->win, e->mlx_img.img, 0, 0);
	print_helper_strings(e);
	return (1);
}
