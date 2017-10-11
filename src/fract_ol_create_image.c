/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_create_image.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 00:50:55 by fhuang            #+#    #+#             */
/*   Updated: 2017/04/22 15:56:39 by FannyHuang       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fract_ol.h"
#include "libft.h"

#define IMAGE_WIDTH 500
#define IMAGE_HEIGHT 500

# define COORD_X1 fractal.coord[0]
# define COORD_X2 fractal.coord[1]
# define COORD_Y1 fractal.coord[2]
# define COORD_Y2 fractal.coord[3]

void	fract_ol_put_pixel_img(t_mlx_img *img, int x, int y, int r, int g, int b)
{
	x *= 4;
	if (y >= 0 && y < IMAGE_HEIGHT && x >= 0 && x < img->size_line)
	{
		img->address[y * img->size_line + x] = b;//((r & 0xff) << 16);
		// img->address[y * img->size_line + x] = (char)255;
		x++;
		img->address[y * img->size_line + x] = g;// ((g & 0xff) << 8);
		x++;
		img->address[y * img->size_line + x] = r;//(b & 0xff);
	}
}

void	fract_ol_draw_fractal(t_mlx_img *mlx_img)
{
	double	z_r = 0;
	double	z_i = 0;
	double	c_r = 0;
	double	c_i = 0;

	double	tmp_r = 0;

	double	i;
	for (unsigned int x = 0; x < IMAGE_WIDTH; x++)
	{
		// c_r = 1.5 * (x - IMAGE_WIDTH / 2.0) / (0.5 * IMAGE_WIDTH * mlx_img->fractal.zoom) + mlx_img->COORD_X1 ;
		c_r = x / mlx_img->fractal.zoom + mlx_img->COORD_X1 ;
		for (unsigned int y = 0; y < IMAGE_HEIGHT; y++)
		{
			// c_i = (y - IMAGE_HEIGHT / 2.0) / (0.5 * IMAGE_HEIGHT * mlx_img->fractal.zoom) + mlx_img->COORD_Y1 ;
			i = 0;
			z_r = 0;
			z_i = 0;
			c_i = y / mlx_img->fractal.zoom + mlx_img->COORD_Y1;
			// printf("| %lf |", c_i);
			while (i < mlx_img->fractal.iteration &&\
				z_r * z_r + z_i * z_i < 4.0)
			{
				tmp_r = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2.0 * z_i * tmp_r + c_i;
				i++;
			}

			if (i == mlx_img->fractal.iteration)
				fract_ol_put_pixel_img(mlx_img, x, y, 0x0, 0x0, 0x0);
			else
			{
				if (i >= 200)//#2df909
				fract_ol_put_pixel_img(mlx_img, x, y, 0xee, 0x58, 0x59);
				else if (i > 50 && i < 200)//#3f9630
				fract_ol_put_pixel_img(mlx_img, x, y, 0x3f, 0x96, 0x30);
				else if (i > 5)//#c4f2bc
				fract_ol_put_pixel_img(mlx_img, x, y, 0xf0, 0xf0, 0xf0);
				else
				fract_ol_put_pixel_img(mlx_img, x, y, 0xce, 0xc3, 0xa7);
			}
		}
	}
}

int		fract_ol_create_image(t_env *e) // 2nd param -> fractal name
{
	if (!(e->mlx_img.img = mlx_new_image(e->mlx, IMAGE_WIDTH, IMAGE_HEIGHT)))
		return (0);
	e->mlx_img.address = mlx_get_data_addr(e->mlx_img.img,\
		&e->mlx_img.bits_per_pixel, &e->mlx_img.size_line, &e->mlx_img.endian);
		ft_printf("address: %p\n", e->mlx_img.address);
	fract_ol_draw_fractal(&e->mlx_img);
	mlx_put_image_to_window(e->mlx, e->win, e->mlx_img.img, 0, 0);
	return (1);
}
