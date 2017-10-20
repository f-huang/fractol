/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_create_image.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 00:50:55 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/20 17:04:46 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fract_ol.h"
#include "libft.h"


#include <stdio.h>
static void	put_pixel_in_fract_ol(t_mlx_img *mlx_img, t_offset offset, double i)
{
	t_rgb	rgb;

	ft_bzero(&rgb, sizeof(rgb));
	if (i == mlx_img->fractal.iteration)
		rgb = (t_rgb) { .r = 0x0, .g = 0x0, .b = 0x0 };
	else
	{
		if (i >= 200)//#2df909
			rgb = (t_rgb) { .r = 0xee, .g = 0x58, .b = 0x59 };
		else if (i > 50 && i < 200)//#3f9630
			rgb = (t_rgb) { .r = 0x3f, .g = 0x96, .b = 0x30 };
		else if (i > 5)//#c4f2bc
			rgb = (t_rgb) { .r = 0xf0, .g = 0xf0, .b = 0xf0 };
		else
			rgb = (t_rgb) { .r = 0xce, .g = 0xc3, .b = 0xa7 };
	}
	fract_ol_put_pixel_img(mlx_img, offset, rgb);
}

static double	define_z_complex(t_complex c, unsigned int max_iterations)
{
	double		i;
	double		tmp_real;
	t_complex	z;

	ft_bzero(&z, sizeof(t_complex));
	i = -1;
	while (++i < max_iterations\
		&& z.real * z.real + z.imaginary * z.imaginary < 4.0)
	{
		tmp_real = z.real;
		z.real = z.real * z.real - z.imaginary * z.imaginary + c.real;
		z.imaginary = 2.0 * z.imaginary * tmp_real + c.imaginary;
	}
	return (i);
}

static void	fract_ol_draw_fractal(t_mlx_img *mlx_img)
{
	t_complex	c;
	t_offset	offset;
	double		i;

	ft_bzero(&offset, sizeof(t_offset));
	ft_bzero(&c, sizeof(t_complex));
	while (offset.x < mlx_img->width)
	{
		c.real = offset.x / mlx_img->fractal.zoom + mlx_img->fractal.x;
		offset.y = 0;
		while (offset.y < mlx_img->height)
		{
			c.imaginary = offset.y / mlx_img->fractal.zoom + mlx_img->fractal.y;
			i = define_z_complex(c, mlx_img->fractal.iteration);
			put_pixel_in_fract_ol(mlx_img, offset, i);
			++offset.y;
		}
		++offset.x;
	}
}

int		fract_ol_create_image(t_env *e) // 2nd param -> fractal name
{
	e->mlx_img.width = IMAGE_WIDTH;
	e->mlx_img.height = IMAGE_HEIGHT;
	// e->mlx_img.width = ft_abs(e->mlx_img.fractal.abscissa.max - e->mlx_img.fractal.abscissa.min) * e->mlx_img.fractal.zoom;
	// e->mlx_img.height = ft_abs(e->mlx_img.fractal.ordinate.max - e->mlx_img.fractal.ordinate.min) * e->mlx_img.fractal.zoom;
	if (!(e->mlx_img.img = mlx_new_image(e->mlx, (int)e->mlx_img.width, (int)e->mlx_img.height)))
		return (0);
	e->mlx_img.address = mlx_get_data_addr(e->mlx_img.img,\
		&e->mlx_img.bits_per_pixel, &e->mlx_img.size_line, &e->mlx_img.endian);
	ft_printf("address: %p\n", e->mlx_img.address);
	fract_ol_draw_fractal(&e->mlx_img);

	mlx_put_image_to_window(e->mlx, e->win, e->mlx_img.img, 0, 0);
	return (1);
}
