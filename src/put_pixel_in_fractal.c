/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel_in_fractal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 13:13:11 by fhuang            #+#    #+#             */
/*   Updated: 2017/11/02 19:22:50 by fhuang           ###   ########.fr       */
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
		img->address[offset.y * img->size_line + offset.x] = rgb.b;
		img->address[offset.y * img->size_line + offset.x + 1] = rgb.g;
		img->address[offset.y * img->size_line + offset.x + 2] = rgb.r;
	}
	(void)rgb;
}

static void	pick_color(t_rgb *rgb, t_mlx_img *mlx_img, t_fractal fractal, int i)
{
	t_rgb			*colors;
	double			coef;

	colors = ft_memalloc(sizeof(t_rgb) * NB_COLORS);
	if (!colors)
		return ;
	coef = ((i * 255) / fractal.iteration);
	if (!coef)
		coef = 255;
	colors[F_BW] = (t_rgb) {
		.r = 255 - (10 * i), .g = 255 - (10 * i), .b = 255 - (10 * i) };
	colors[F_RED] = (t_rgb) { .r = 10 * i, .g = 10 / coef, .b = 10 / coef };
	colors[F_BLUE] = (t_rgb) { .r = 100 / coef, .g = 100 / coef, .b = 10 * coef };
	colors[F_GREEN] = (t_rgb) { .r = 10 / coef, .g = 10 * i, .b = 10 / coef };
	colors[F_RANDOM_1] = (t_rgb) {
		.r = 250 * coef, .g = 250 * coef, .b = 250 * i };
	colors[F_PINK] = (t_rgb) { .r = coef, .g = coef / 2, .b = coef };
	ft_memcpy(rgb, colors + mlx_img->color, sizeof(t_rgb));
	ft_memdel((void**)&colors);
}

void		put_pixel_in_fractal(
		t_mlx_img *mlx_img, t_fractal fractal, t_offset offset, int i)
{
	t_rgb	*rgb;

	rgb = (t_rgb*)ft_memalloc(sizeof(t_rgb));
	if (i == fractal.iteration)
		*rgb = (t_rgb) { .r = 0x0, .g = 0x0, .b = 0x0 };
	else
		pick_color(rgb, mlx_img, fractal, i);
	put_pixel_img(mlx_img, offset, *rgb);
	ft_memdel((void**)&rgb);
}
