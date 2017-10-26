/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_create_image.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 00:50:55 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/26 23:11:12 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fract_ol.h"
#include "libft.h"

#include <stdio.h>

static int	define_z_complex(t_complex c, int max_iterations)
{
	int			i;
	long double	square_z;
	long double	square_imaginary;
	t_complex	z;

	ft_bzero(&z, sizeof(t_complex));
	i = -1;
	while (++i < max_iterations\
		&& (square_z = z.real * z.real)
			+ (square_imaginary = z.imaginary * z.imaginary) < 4.0)
	{
		z = (t_complex) {
			.imaginary = 2.0 * z.imaginary * z.real + c.imaginary,
			.real = square_z - square_imaginary + c.real
		};
	}
	return (i);
}

static void	*draw_depending_on_range(void *args)
{
	t_draw_helper	*helper;
	t_complex		c;
	int				i;

	helper = (t_draw_helper*)args;
	ft_bzero(&c, sizeof(t_complex));
	while (helper->offset.x < helper->range.x)
	{
		c.real = helper->offset.x / helper->img->fractal.zoom + helper->img->fractal.abscissa.min;
		helper->offset.y = 0;
		while (helper->offset.y < helper->range.y)
		{
			c.imaginary = helper->offset.y / helper->img->fractal.zoom + helper->img->fractal.ordinate.min;
			i = define_z_complex(c, helper->img->fractal.iteration);
			put_pixel_in_fractal(helper->img, helper->offset, i);
			++helper->offset.y;
		}
		++helper->offset.x;
	}
	return (NULL);
}

static void	fract_ol_draw_fractal(t_env *e)
{
	static int		piece_of_image = 0;
	t_draw_helper	helper[NB_THREADS];
	int				j;
	int				nb_loop;

	if (!piece_of_image)
		piece_of_image = e->mlx_img.width / NB_THREADS + ((int)e->mlx_img.width % NB_THREADS ? 1 : 0);
	nb_loop = e->mlx_img.width / piece_of_image + ((int)e->mlx_img.width % piece_of_image ? 1 : 0);
	j = 0;
	while (j < nb_loop)
	{
		helper[j] = (t_draw_helper) {
			.img = &e->mlx_img,
			.offset = (t_offset) { .x = piece_of_image * j, .y = 0 },
			.range = (t_offset) { .x = (piece_of_image * (j + 1) > e->mlx_img.width ?\
				e->mlx_img.width : piece_of_image * (j + 1)), .y = e->mlx_img.height }
		};
		pthread_create(&e->thread[j], NULL, draw_depending_on_range, &helper[j]);
		j++;
	}
	while (j >= 0)
		pthread_join(e->thread[j--], NULL);
}

int		fract_ol_create_image(t_env *e) // 2nd param -> fractal name
{
	if (!(e->mlx_img.img = mlx_new_image(e->mlx, (int)e->mlx_img.width, (int)e->mlx_img.height)))
		return (0);
	e->mlx_img.address = mlx_get_data_addr(e->mlx_img.img,\
		&e->mlx_img.bits_per_pixel, &e->mlx_img.size_line, &e->mlx_img.endian);
	fract_ol_draw_fractal(e);
	mlx_put_image_to_window(e->mlx, e->win, e->mlx_img.img, 0, 0);
	return (1);
}
