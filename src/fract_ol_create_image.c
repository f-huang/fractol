/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_create_image.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 00:50:55 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/21 15:21:06 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fract_ol.h"
#include "libft.h"

#include <stdio.h>

static double	define_z_complex(t_complex c, unsigned int max_iterations)
{
	double		i;
	double		square_z;
	double		square_imaginary;
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
	t_complex	c;
	double		i;

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
	t_draw_helper	helper;
	int				i;
	int				j;
	unsigned int	tmp;

	tmp = e->mlx_img.width / 9 - (int)e->mlx_img.width % 9;
	i = 0;
	j = 0;
	while (i < e->mlx_img.width)
	{
		helper = (t_draw_helper) {
			.img = &e->mlx_img,
			.offset = (t_offset) { .x = tmp * j, .y = 0 },
			.range = (t_offset) { .x = (tmp * (j + 1) > e->mlx_img.width ?\
				e->mlx_img.width : tmp * (j + 1)), .y = e->mlx_img.height }
		};
		printf("%u - %u\n", helper.offset.x, helper.offset.y);
		printf("%u - %u\n----------\n", helper.range.x, helper.range.y);
		pthread_create(&e->thread[j], NULL, draw_depending_on_range, &helper);
		i += 100;
		j++;
	}
	pthread_join(e->thread[0], NULL);
	pthread_join(e->thread[1], NULL);
	pthread_join(e->thread[2], NULL);
	pthread_join(e->thread[3], NULL);
	pthread_join(e->thread[4], NULL);
	pthread_join(e->thread[5], NULL);
	pthread_join(e->thread[6], NULL);
	pthread_join(e->thread[7], NULL);
	pthread_join(e->thread[8], NULL);
}

int		fract_ol_create_image(t_env *e) // 2nd param -> fractal name
{
	e->mlx_img.width = IMAGE_WIDTH;
	e->mlx_img.height = IMAGE_HEIGHT;
	if (!(e->mlx_img.img = mlx_new_image(e->mlx, (int)e->mlx_img.width, (int)e->mlx_img.height)))
		return (0);
	e->mlx_img.address = mlx_get_data_addr(e->mlx_img.img,\
		&e->mlx_img.bits_per_pixel, &e->mlx_img.size_line, &e->mlx_img.endian);
	fract_ol_draw_fractal(e);
	mlx_put_image_to_window(e->mlx, e->win, e->mlx_img.img, 0, 0);
	return (1);
}
