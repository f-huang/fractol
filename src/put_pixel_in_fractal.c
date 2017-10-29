/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel_in_fractal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 13:13:11 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/29 21:59:35 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fract_ol.h"

static void	put_pixel_img(t_mlx_img *img, t_offset offset, t_rgb rgb)
{
	offset.x *= 4;
	if (offset.y < img->size\
		&& offset.x < (unsigned int)img->size_line)
	{
		img->address[offset.y * img->size_line + offset.x] = rgb.b >> 8;
		img->address[offset.y * img->size_line + offset.x + 1] = rgb.g >> 8;
		img->address[offset.y * img->size_line + offset.x + 2] = rgb.r;
	}
}

void		put_pixel_in_fractal(t_mlx_img *mlx_img, t_offset offset, int i)
{
	if (i == mlx_img->fractal.iteration)
		mlx_img->rgb = (t_rgb) { .r = 0x0, .g = 0x0, .b = 0x0 };
	else
		mlx_img->rgb = (t_rgb) { .r = 255 - i * 10, .g = 255 - i * 100, .b = 255 - i * 100 };
	put_pixel_img(mlx_img, offset, mlx_img->rgb);
}
// 10 10 10
