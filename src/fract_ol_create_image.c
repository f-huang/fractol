/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_create_image.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 00:50:55 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/29 20:51:33 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fract_ol.h"

static void	fract_ol_draw_fractal(t_env *e)
{
	static int		piece_of_image = 0;
	static int		nb_loop = 0;
	t_draw_helper	helper[NB_THREADS];
	int				j;

	if (!piece_of_image)
		piece_of_image = e->mlx_img.size / NB_THREADS + ((int)e->mlx_img.size % NB_THREADS ? 1 : 0);
	if (!nb_loop)
		nb_loop = e->mlx_img.size / piece_of_image + ((int)e->mlx_img.size % piece_of_image ? 1 : 0);
	j = 0;
	while (j < nb_loop)
	{
		helper[j] = (t_draw_helper) {
			.img = &e->mlx_img,
			.offset = (t_offset) { .x = piece_of_image * j, .y = 0 },
			.range = (t_offset) { .x = (piece_of_image * (j + 1) > e->mlx_img.size ?\
				e->mlx_img.size : piece_of_image * (j + 1)), .y = e->mlx_img.size },
			// .c = e->mlx_img.fractal.motion_complex
		};
		draw_corresponding_fractal(&helper[j], &e->thread[j], e->mlx_img.fractal.type);
		j++;
	}
	while (j >= 0)
		pthread_join(e->thread[j--], NULL);
}

int		fract_ol_create_image(t_env *e) // 2nd param -> fractal name
{
	if (!(e->mlx_img.img = mlx_new_image(e->mlx, (int)e->mlx_img.size, (int)e->mlx_img.size)))
		return (0);
	e->mlx_img.address = mlx_get_data_addr(e->mlx_img.img,\
		&e->mlx_img.bits_per_pixel, &e->mlx_img.size_line, &e->mlx_img.endian);
	fract_ol_draw_fractal(e);
	mlx_put_image_to_window(e->mlx, e->win, e->mlx_img.img, 0, 0);
	return (1);
}
