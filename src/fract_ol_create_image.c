/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_create_image.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 00:50:55 by fhuang            #+#    #+#             */
/*   Updated: 2017/11/02 14:13:02 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fract_ol.h"

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
	return (1);
}
