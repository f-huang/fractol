/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel_in_fractal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 13:13:11 by fhuang            #+#    #+#             */
/*   Updated: 2017/11/02 11:17:10 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fract_ol.h"
#include <stdio.h>
static void	put_pixel_img(t_mlx_img *img, t_offset offset, t_rgb rgb)
{
	offset.x *= 4;
	if (offset.y < img->size\
		&& offset.x < (unsigned int)img->size_line)
	{
		img->address[offset.y * img->size_line + offset.x] = rgb.r;
		img->address[offset.y * img->size_line + offset.x + 1] = rgb.g;
		img->address[offset.y * img->size_line + offset.x + 2] = rgb.b;
	}
	(void)rgb;
}

void		put_pixel_in_fractal(t_mlx_img *mlx_img, t_fractal fractal, t_offset offset, int i)
{
	t_rgb	rgb;

	if (i == fractal.iteration)
		rgb = (t_rgb) { .r = 0x0, .g = 0x0, .b = 0x0 };
	else {
		rgb = (t_rgb) {
			.r =  i * mlx_img->rgb.r,
			.g =  i * mlx_img->rgb.b,
			.b =  i * mlx_img->rgb.g
		};
		// printf("%i - %i - %i\n", rgb.r, rgb.g, rgb.r);
	}
	put_pixel_img(mlx_img, offset, rgb);
}
